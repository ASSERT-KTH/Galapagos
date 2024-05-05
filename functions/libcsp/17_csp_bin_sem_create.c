int csp_bin_sem_create(csp_bin_sem_handle_t * sem) {
	csp_log_lock("Semaphore init: %p", sem);
	if (sem_init(sem, 0, 1) == 0) {
		return CSP_SEMAPHORE_OK;
	}

	return CSP_SEMAPHORE_ERROR;
}