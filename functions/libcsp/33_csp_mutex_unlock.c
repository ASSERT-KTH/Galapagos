int csp_mutex_unlock(csp_mutex_t * mutex) {
	if (pthread_mutex_unlock(mutex) == 0) {
		return CSP_SEMAPHORE_OK;
	}

	return CSP_SEMAPHORE_ERROR;
}