int csp_bin_sem_post_isr(csp_bin_sem_handle_t * sem, CSP_BASE_TYPE * pxTaskWoken) {
	csp_log_lock("Post: %p", sem);
	if (xSemaphoreGiveFromISR(*sem, pxTaskWoken) == pdPASS) {
		return CSP_SEMAPHORE_OK;
	} else {
		return CSP_SEMAPHORE_ERROR;
	}
}