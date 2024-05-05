int windows_queue_dequeue(windows_queue_t * queue, void * buf, int timeout) {

	EnterCriticalSection(&(queue->mutex));
	while(queueEmpty(queue)) {
		int ret = SleepConditionVariableCS(&(queue->cond_empty), &(queue->mutex), timeout);
		if( !ret ) {
			LeaveCriticalSection(&(queue->mutex));
			return ret == WAIT_TIMEOUT ? WINDOWS_QUEUE_EMPTY : WINDOWS_QUEUE_ERROR;
		}
	}
	memcpy(buf, (unsigned char*)queue->buffer+(queue->head_idx%queue->size*queue->item_size), queue->item_size);
	queue->items--;
	queue->head_idx = (queue->head_idx + 1) % queue->size;

	LeaveCriticalSection(&(queue->mutex));
	WakeAllConditionVariable(&(queue->cond_full));
	return WINDOWS_QUEUE_OK;
}