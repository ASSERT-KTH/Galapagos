pthread_mutex_unlock (_GL_UNUSED pthread_mutex_t *mutex)
{
  /* There is only one thread, so it always unlocks successfully.
     This implementation does not support robust mutexes or
     PTHREAD_MUTEX_ERRORCHECK.  */
  return 0;
}