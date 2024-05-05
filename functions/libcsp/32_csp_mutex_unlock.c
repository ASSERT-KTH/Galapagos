int csp_mutex_unlock(csp_mutex_t * mutex) {
	int dummy = 0;
	if (pthread_queue_enqueue(*mutex, &dummy, 0) == PTHREAD_QUEUE_OK) {
		return CSP_SEMAPHORE_OK;
	}
	return CSP_SEMAPHORE_ERROR;
}