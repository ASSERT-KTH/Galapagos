void csp_buf_free(uint8_t node, uint32_t timeout) {

	uint32_t size;
	int err = csp_get_buf_free(node, timeout, &size);
	if (err == CSP_ERR_NONE) {
		printf("Free buffers at node %u is %"PRIu32"\r\n", node, size);
	} else {
		printf("Network error\r\n");
	}

}