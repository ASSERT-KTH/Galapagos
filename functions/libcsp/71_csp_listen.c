int csp_listen(csp_socket_t * socket, size_t backlog) {
	
	if (socket == NULL)
		return CSP_ERR_INVAL;

	socket->socket = csp_queue_create(backlog, sizeof(csp_conn_t *));
	if (socket->socket == NULL)
		return CSP_ERR_NOMEM;

        socket->opts |= CSP_SO_INTERNAL_LISTEN;

	return CSP_ERR_NONE;

}