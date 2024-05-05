void csp_memfree(uint8_t node, uint32_t timeout) {

	uint32_t memfree;
        int err = csp_get_memfree(node, timeout, &memfree);
	if (err == CSP_ERR_NONE) {
		printf("Free Memory at node %u is %"PRIu32" bytes\r\n", node, memfree);
	} else {
		printf("Network error\r\n");
	}

}