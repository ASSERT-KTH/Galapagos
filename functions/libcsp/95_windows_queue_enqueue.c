int windows_queue_enqueue(windows_queue_t * queue, const void * value, int timeout) {

	int offset;
	EnterCriticalSection(&(queue->mutex));
	while(queueFull(queue)) {
		int ret = SleepConditionVariableCS(&(queue->cond_full), &(queue->mutex), timeout);
		if( !ret ) {
			LeaveCriticalSection(&(queue->mutex));
			return ret == WAIT_TIMEOUT ? WINDOWS_QUEUE_FULL : WINDOWS_QUEUE_ERROR;
		}
	}
	offset = ((queue->head_idx+queue->items) % queue->size) * queue->item_size;
	memcpy((unsigned char*)queue->buffer + offset, value, queue->item_size);
	queue->items++;

	LeaveCriticalSection(&(queue->mutex));
	WakeAllConditionVariable(&(queue->cond_empty));
	return WINDOWS_QUEUE_OK;
}