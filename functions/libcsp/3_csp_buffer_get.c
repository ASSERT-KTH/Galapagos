void *csp_buffer_get(size_t _data_size) {

	if (_data_size > csp_conf.buffer_data_size) {
		csp_log_error("GET: Attempt to allocate too large data size %u > max %u", (unsigned int) _data_size, (unsigned int) csp_conf.buffer_data_size);
		return NULL;
	}

	csp_skbf_t * buffer = NULL;
	csp_queue_dequeue(csp_buffers, &buffer, 0);
	if (buffer == NULL) {
		csp_log_error("GET: Out of buffers");
		return NULL;
	}

	if (buffer != buffer->skbf_addr) {
		csp_log_error("GET: Corrupt CSP buffer %p != %p", buffer, buffer->skbf_addr);
		return NULL;
	}

	csp_log_buffer("GET: %p", buffer);

	buffer->refcount = 1;
	return buffer->skbf_data;
}