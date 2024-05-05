int csp_bin_sem_wait(csp_bin_sem_handle_t * sem, uint32_t timeout) {
	csp_log_lock("Wait: %p", sem);
	if (timeout != CSP_MAX_TIMEOUT) {
		timeout = timeout / portTICK_RATE_MS;
	}
	if (xSemaphoreTake(*sem, timeout) == pdPASS) {
		return CSP_SEMAPHORE_OK;
	}
	return CSP_SEMAPHORE_ERROR;
}