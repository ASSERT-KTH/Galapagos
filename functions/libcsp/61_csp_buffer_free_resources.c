void csp_buffer_free_resources(void) {

	if (csp_buffers) {
		csp_queue_remove(csp_buffers);
		csp_buffers = NULL;
	}
	csp_free(csp_buffer_pool);
	csp_buffer_pool = NULL;

}