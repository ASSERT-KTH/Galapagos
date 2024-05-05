int csp_mutex_create(csp_mutex_t * mutex) {
	csp_log_lock("Mutex init: %p", mutex);
	*mutex = pthread_queue_create(1, sizeof(int));
	if (*mutex) {
		int dummy = 0;
		pthread_queue_enqueue(*mutex, &dummy, 0);
		return CSP_SEMAPHORE_OK;
	}

	return CSP_SEMAPHORE_ERROR;
}