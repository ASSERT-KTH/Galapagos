int csp_rdp_init(csp_conn_t * conn) {

	csp_log_protocol("RDP %p: Creating RDP queues", conn);

	/* Set initial state */
	conn->rdp.state = RDP_CLOSED;
	conn->rdp.conn_timeout = csp_rdp_conn_timeout;
	conn->rdp.packet_timeout = csp_rdp_packet_timeout;

	/* Create a binary semaphore to wait on for tasks */
	if (csp_bin_sem_create(&conn->rdp.tx_wait) != CSP_SEMAPHORE_OK) {
		csp_log_error("RDP %p: Failed to initialize semaphore", conn);
		return CSP_ERR_NOMEM;
	}

	/* Create TX queue */
	conn->rdp.tx_queue = csp_queue_create(csp_conf.rdp_max_window, sizeof(csp_packet_t *));
	if (conn->rdp.tx_queue == NULL) {
		csp_log_error("RDP %p: Failed to create TX queue for conn", conn);
		csp_bin_sem_remove(&conn->rdp.tx_wait);
		return CSP_ERR_NOMEM;
	}

	/* Create RX queue */
	conn->rdp.rx_queue = csp_queue_create(csp_conf.rdp_max_window * 2, sizeof(csp_packet_t *));
	if (conn->rdp.rx_queue == NULL) {
		csp_log_error("RDP %p: Failed to create RX queue for conn", conn);
		csp_bin_sem_remove(&conn->rdp.tx_wait);
		csp_queue_remove(conn->rdp.tx_queue);
		return CSP_ERR_NOMEM;
	}

	return CSP_ERR_NONE;

}