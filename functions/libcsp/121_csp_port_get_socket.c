csp_socket_t * csp_port_get_socket(unsigned int port) {

	if (port > csp_conf.port_max_bind) {
		return NULL;
	}

	/* Match dport to socket or local "catch all" port number */
	if (ports[port].state == PORT_OPEN) {
		return ports[port].socket;
	}

	if (ports[csp_conf.port_max_bind + 1].state == PORT_OPEN) {
		return ports[csp_conf.port_max_bind + 1].socket;
	}

	return NULL;

}