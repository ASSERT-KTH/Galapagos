int csp_mutex_lock(csp_mutex_t * mutex, uint32_t timeout) {

	csp_log_lock("Wait: %p timeout %"PRIu32, mutex, timeout);

	int dummy = 0;
	if (pthread_queue_dequeue(*mutex, &dummy, timeout) == PTHREAD_QUEUE_OK) {
		return CSP_SEMAPHORE_OK;
	}

	return CSP_SEMAPHORE_ERROR;
}