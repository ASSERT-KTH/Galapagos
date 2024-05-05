int csp_mutex_lock(csp_mutex_t * mutex, uint32_t timeout) {

	int ret;

	csp_log_lock("Wait: %p timeout %"PRIu32, mutex, timeout);

	if (timeout == CSP_MAX_TIMEOUT) {
		ret = pthread_mutex_lock(mutex);
	} else {
		struct timespec ts;
		if (clock_gettime(CLOCK_REALTIME, &ts)) {
			return CSP_SEMAPHORE_ERROR;
		}

		uint32_t sec = timeout / 1000;
		uint32_t nsec = (timeout - 1000 * sec) * 1000000;

		ts.tv_sec += sec;

		if (ts.tv_nsec + nsec >= 1000000000) {
			ts.tv_sec++;
		}

		ts.tv_nsec = (ts.tv_nsec + nsec) % 1000000000;

		ret = pthread_mutex_timedlock(mutex, &ts);
	}

	if (ret != 0)
		return CSP_SEMAPHORE_ERROR;

	return CSP_SEMAPHORE_OK;
}