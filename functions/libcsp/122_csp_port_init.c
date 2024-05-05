int csp_port_init(void) {

	ports = csp_calloc(csp_conf.port_max_bind + 2, sizeof(*ports)); // +2 for max port and CSP_ANY
	if (ports == NULL) {
		return CSP_ERR_NOMEM;
	}

	return CSP_ERR_NONE;

}