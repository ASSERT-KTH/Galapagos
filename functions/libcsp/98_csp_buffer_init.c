int csp_buffer_init(void) {

	// calculate total size and ensure correct alignment (int *) for buffers
	const unsigned int skbfsize = CSP_BUFFER_ALIGN * ((sizeof(csp_skbf_t) + csp_buffer_size() + (CSP_BUFFER_ALIGN - 1)) / CSP_BUFFER_ALIGN);

	csp_buffer_pool = csp_malloc(csp_conf.buffers * skbfsize);
	if (csp_buffer_pool == NULL)
		goto fail_malloc;

	csp_buffers = csp_queue_create(csp_conf.buffers, sizeof(void *));
	if (!csp_buffers)
		goto fail_queue;

	for (unsigned int i = 0; i < csp_conf.buffers; i++) {
		csp_skbf_t * buf = (void *) &csp_buffer_pool[i * skbfsize];
		buf->skbf_addr = buf;
		csp_queue_enqueue(csp_buffers, &buf, 0);
	}

	return CSP_ERR_NONE;

fail_queue:
	csp_buffer_free_resources();
fail_malloc:
	return CSP_ERR_NOMEM;

}