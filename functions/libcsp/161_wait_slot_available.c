static inline int wait_slot_available(pthread_queue_t * queue, struct timespec *ts) {

	int ret;

	while (queue->items == queue->size) {

		if (ts != NULL) {
			ret = pthread_cond_timedwait(&(queue->cond_full), &(queue->mutex), ts);
		} else {
			ret = pthread_cond_wait(&(queue->cond_full), &(queue->mutex));
		}

		if (ret != 0 && errno != EINTR) {
			return PTHREAD_QUEUE_FULL; //Timeout
		}
	}

	return PTHREAD_QUEUE_OK;

}