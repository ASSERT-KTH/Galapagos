int csp_bin_sem_remove(csp_bin_sem_handle_t * sem) {
	if (sem_destroy(sem) == 0) {
		return CSP_SEMAPHORE_OK;
	}

	return CSP_SEMAPHORE_ERROR;
}