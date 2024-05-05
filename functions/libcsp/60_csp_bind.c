int csp_bind(csp_socket_t * socket, uint8_t port) {
	
	if (socket == NULL)
		return CSP_ERR_INVAL;

	if (port == CSP_ANY) {
		port = csp_conf.port_max_bind + 1;
	} else if (port > csp_conf.port_max_bind) {
		csp_log_error("csp_bind: invalid port %u, only ports from 0-%u (+ CSP_ANY for default) are available for incoming ports", port, csp_conf.port_max_bind);
		return CSP_ERR_INVAL;
	}

	if (ports[port].state != PORT_CLOSED) {
		csp_log_error("Port %d is already in use", port);
		return CSP_ERR_USED;
	}

	csp_log_info("Binding socket %p to port %u", socket, port);

	/* Save listener */
	ports[port].socket = socket;
	ports[port].state = PORT_OPEN;

	return CSP_ERR_NONE;

}