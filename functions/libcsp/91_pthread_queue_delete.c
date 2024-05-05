void pthread_queue_delete(pthread_queue_t * q) {

	if (q == NULL)
		return;

	csp_free(q->buffer);
	csp_free(q);

	return;

}