int csp_bin_sem_post(csp_bin_sem_handle_t * sem) {
	csp_log_lock("Post: %p", sem);

	int value;
	sem_getvalue(sem, &value);
	if (value > 0) {
		return CSP_SEMAPHORE_OK;
	}

	if (sem_post(sem) == 0) {
		return CSP_SEMAPHORE_OK;
	}

	return CSP_SEMAPHORE_ERROR;
}