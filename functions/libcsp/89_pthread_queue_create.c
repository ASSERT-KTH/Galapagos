pthread_queue_t * pthread_queue_create(int length, size_t item_size) {
	
	pthread_queue_t * q = csp_malloc(sizeof(pthread_queue_t));
	
	if (q != NULL) {
		q->buffer = csp_malloc(length*item_size);
		if (q->buffer != NULL) {
			q->size = length;
			q->item_size = item_size;
			q->items = 0;
			q->in = 0;
			q->out = 0;
			if (pthread_mutex_init(&(q->mutex), NULL) || init_cond_clock_monotonic(&(q->cond_full)) || init_cond_clock_monotonic(&(q->cond_empty))) {
				csp_free(q->buffer);
				csp_free(q);
				q = NULL;
			}
		} else {
			csp_free(q);
			q = NULL;
		}
	}

	return q;
	
}