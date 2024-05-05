int csp_get_uptime(uint8_t node, uint32_t timeout, uint32_t * uptime) {

	int status = csp_transaction(CSP_PRIO_NORM, node, CSP_UPTIME, timeout, NULL, 0, uptime, sizeof(*uptime));
	if (status == sizeof(*uptime)) {
		*uptime = csp_ntoh32(*uptime);
		return CSP_ERR_NONE;
	}
	*uptime = 0;
	return CSP_ERR_TIMEDOUT;
}