pthread_mutex_unlock (pthread_mutex_t *mutex)
{
  switch (mutex->type)
    {
    case 1:
      return glwthread_timedmutex_unlock (&mutex->u.u_timedmutex);
    case 2:
      return glwthread_timedrecmutex_unlock (&mutex->u.u_timedrecmutex);
    default:
      abort ();
    }
}