int csp_mutex_create(csp_mutex_t * mutex) {
	csp_log_lock("Mutex init: %p", mutex);
	if (pthread_mutex_init(mutex, NULL) == 0) {
		return CSP_SEMAPHORE_OK;
	}

	return CSP_SEMAPHORE_ERROR;
}