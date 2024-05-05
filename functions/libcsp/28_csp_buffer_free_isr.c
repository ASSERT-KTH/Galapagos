void csp_buffer_free_isr(void *packet) {

	if (packet == NULL) {
		// freeing a NULL pointer is OK, e.g. standard free()
		return;
	}

	csp_skbf_t * buf = (void*)(((uint8_t*)packet) - sizeof(csp_skbf_t));

	if (((uintptr_t) buf % CSP_BUFFER_ALIGN) > 0) {
		return;
	}

	if (buf->skbf_addr != buf) {
		return;
	}

	if (buf->refcount == 0) {
		return;
	}

	if (--(buf->refcount) > 0) {
		return;
	}

	CSP_BASE_TYPE task_woken = 0;
	csp_queue_enqueue_isr(csp_buffers, &buf, &task_woken);

}