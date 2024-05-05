int csp_mutex_remove(csp_mutex_t * mutex) {
	if (pthread_mutex_destroy(mutex) == 0) {
		return CSP_SEMAPHORE_OK;
	}

	return CSP_SEMAPHORE_ERROR;
}