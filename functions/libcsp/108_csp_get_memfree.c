int csp_get_memfree(uint8_t node, uint32_t timeout, uint32_t * size) {

	int status = csp_transaction(CSP_PRIO_NORM, node, CSP_MEMFREE, timeout, NULL, 0, size, sizeof(*size));
	if (status == sizeof(*size)) {
		*size = csp_ntoh32(*size);
		return CSP_ERR_NONE;
	}
	*size = 0;
	return CSP_ERR_TIMEDOUT;

}