windows_queue_t * windows_queue_create(int length, size_t item_size) {

	windows_queue_t *queue = (windows_queue_t*)malloc(sizeof(windows_queue_t));
	if(queue == NULL)
		goto queue_malloc_failed;

	queue->buffer = malloc(length*item_size);
	if(queue->buffer == NULL)
		goto buffer_malloc_failed;

	queue->size = length;
	queue->item_size = item_size;
	queue->items = 0;
	queue->head_idx = 0;

	InitializeCriticalSection(&(queue->mutex));
	InitializeConditionVariable(&(queue->cond_full));
	InitializeConditionVariable(&(queue->cond_empty));
	goto queue_init_success;

buffer_malloc_failed:
	free(queue);
	queue = NULL;
queue_malloc_failed:
queue_init_success:
	return queue;
}