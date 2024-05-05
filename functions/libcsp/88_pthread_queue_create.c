pthread_queue_t * pthread_queue_create(int length, size_t item_size) {

	pthread_queue_t * q = malloc(sizeof(pthread_queue_t));

	if (q != NULL) {
		q->buffer = malloc(length*item_size);
		if (q->buffer != NULL) {
			q->size = length;
			q->item_size = item_size;
			q->items = 0;
			q->in = 0;
			q->out = 0;
			if (pthread_mutex_init(&(q->mutex), NULL) || pthread_cond_init(&(q->cond_full), NULL) || pthread_cond_init(&(q->cond_empty), NULL)) {
				free(q->buffer);
				free(q);
				q = NULL;
			}
		} else {
			free(q);
			q = NULL;
		}
	}

	return q;

}