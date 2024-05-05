int windows_queue_items(windows_queue_t * queue) {

	int items;
	EnterCriticalSection(&(queue->mutex));
	items = queue->items;
	LeaveCriticalSection(&(queue->mutex));

	return items;
}