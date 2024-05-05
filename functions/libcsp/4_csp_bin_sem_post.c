int csp_bin_sem_post(csp_bin_sem_handle_t * sem) {
	csp_log_lock("Post: %p", sem);
	if (xSemaphoreGive(*sem) == pdPASS) {
		return CSP_SEMAPHORE_OK;
	}
	return CSP_SEMAPHORE_ERROR;
}