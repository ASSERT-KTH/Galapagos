static inline int wait_item_available(pthread_queue_t * queue, struct timespec *ts) {

	int ret;

	while (queue->items == 0) {

		if (ts != NULL) {
			ret = pthread_cond_timedwait(&(queue->cond_empty), &(queue->mutex), ts);
		} else {
			ret = pthread_cond_wait(&(queue->cond_empty), &(queue->mutex));
		}

		if (ret != 0 && errno != EINTR) {
			return PTHREAD_QUEUE_EMPTY; //Timeout
		}
	}

	return PTHREAD_QUEUE_OK;

}