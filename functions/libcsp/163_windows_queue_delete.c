void windows_queue_delete(windows_queue_t * q) {

	if(q==NULL) return;
	DeleteCriticalSection(&(q->mutex));
	free(q->buffer);
	free(q);
}