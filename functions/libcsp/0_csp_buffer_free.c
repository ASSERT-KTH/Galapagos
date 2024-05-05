void csp_buffer_free(void *packet) {

	if (packet == NULL) {
		/* freeing a NULL pointer is OK, e.g. standard free() */
		return;
	}

	csp_skbf_t * buf = (void*)(((uint8_t*)packet) - sizeof(csp_skbf_t));

	if (((uintptr_t) buf % CSP_BUFFER_ALIGN) > 0) {
		csp_log_error("FREE: Unaligned CSP buffer pointer %p", packet);
		return;
	}

	if (buf->skbf_addr != buf) {
		csp_log_error("FREE: Invalid CSP buffer pointer %p", packet);
		return;
	}

	if (buf->refcount == 0) {
		csp_log_error("FREE: Buffer already free %p", buf);
		return;
	}

	if (--(buf->refcount) > 0) {
		csp_log_error("FREE: Buffer %p in use by %u users", buf, buf->refcount);
		return;
	}

	csp_log_buffer("FREE: %p", buf);
	csp_queue_enqueue(csp_buffers, &buf, 0);

}