void *csp_buffer_get_isr(size_t _data_size) {

	if (_data_size > csp_conf.buffer_data_size)
		return NULL;

	csp_skbf_t * buffer = NULL;
	CSP_BASE_TYPE task_woken = 0;
	csp_queue_dequeue_isr(csp_buffers, &buffer, &task_woken);
	if (buffer == NULL)
		return NULL;

	if (buffer != buffer->skbf_addr)
		return NULL;

	buffer->refcount = 1;
	return buffer->skbf_data;

}