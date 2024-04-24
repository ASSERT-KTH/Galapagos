ldb_cond_wait(ldb_cond_t *cond, ldb_mutex_t *mtx) {
  HANDLE handles[2];
  int last_waiter;
  DWORD result;

  handles[0] = cond->signal;
  handles[1] = cond->broadcast;

  EnterCriticalSection(&cond->lock);
  cond->waiters++;
  LeaveCriticalSection(&cond->lock);

  LeaveCriticalSection(&mtx->handle);

  result = WaitForMultipleObjects(2, handles, FALSE, INFINITE);

  if (result != WAIT_OBJECT_0 && result != WAIT_OBJECT_0 + 1)
    abort(); /* LCOV_EXCL_LINE */

  EnterCriticalSection(&cond->lock);
  cond->waiters--;
  last_waiter = (result == WAIT_OBJECT_0 + 1 && cond->waiters == 0);
  LeaveCriticalSection(&cond->lock);

  if (last_waiter)
    ResetEvent(cond->broadcast);

  EnterCriticalSection(&mtx->handle);
}