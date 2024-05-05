void pthread_queue_delete(pthread_queue_t * q) {

	if (q == NULL)
		return;

	free(q->buffer);
	free(q);

	return;

}