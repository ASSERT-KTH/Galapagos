void csp_uptime(uint8_t node, uint32_t timeout) {

	uint32_t uptime;
	int err = csp_get_uptime(node, timeout, &uptime);
	if (err == CSP_ERR_NONE) {
		printf("Uptime of node %u is %"PRIu32" s\r\n", node, uptime);
	} else {
		printf("Network error\r\n");
	}

}