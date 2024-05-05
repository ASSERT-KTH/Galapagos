csp_conn_t * csp_accept(csp_socket_t * sock, uint32_t timeout) {

	if (sock == NULL)
		return NULL;

	if (sock->socket == NULL)
		return NULL;

	csp_conn_t * conn;
	if (csp_queue_dequeue(sock->socket, &conn, timeout) == CSP_QUEUE_OK)
		return conn;

	return NULL;

}