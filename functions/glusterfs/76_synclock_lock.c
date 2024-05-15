synclock_lock (synclock_t *lock)
{
	int ret = 0;

	pthread_mutex_lock (&lock->guard);
	{
		ret = __synclock_lock (lock);
	}
	pthread_mutex_unlock (&lock->guard);

	return ret;
}