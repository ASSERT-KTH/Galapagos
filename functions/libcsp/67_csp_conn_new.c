csp_conn_t * csp_conn_new(csp_id_t idin, csp_id_t idout) {

	/* Allocate connection structure */
	csp_conn_t * conn = csp_conn_allocate(CONN_CLIENT);

	if (conn) {
		/* No lock is needed here, because nobody else *
		 * has a reference to this connection yet.     */
		conn->idin.ext = idin.ext;
		conn->idout.ext = idout.ext;
		conn->timestamp = csp_get_ms();

		/* Ensure connection queue is empty */
		csp_conn_flush_rx_queue(conn);
	}

	return conn;

}