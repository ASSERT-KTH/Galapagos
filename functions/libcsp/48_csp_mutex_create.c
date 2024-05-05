int csp_mutex_create(csp_mutex_t * mutex) {
	*mutex = xSemaphoreCreateMutex();
	if (*mutex) {
		return CSP_SEMAPHORE_OK;
	} else {
		return CSP_SEMAPHORE_ERROR;
	}
}