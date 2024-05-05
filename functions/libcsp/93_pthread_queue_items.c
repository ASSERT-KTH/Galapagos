int pthread_queue_items(pthread_queue_t * queue) {

	pthread_mutex_lock(&(queue->mutex));
	int items = queue->items;
	pthread_mutex_unlock(&(queue->mutex));
	
	return items;
	
}