static inline int csp_rdp_receive_data(csp_conn_t * conn, csp_packet_t * packet) {

	/* Remove RDP header before passing to userspace */
	csp_rdp_header_remove(packet);

	/* Enqueue data */
	if (csp_conn_enqueue_packet(conn, packet) < 0) {
		csp_log_warn("RDP %p: Conn RX buffer full", conn);
		return CSP_ERR_NOBUFS;
	}

	return CSP_ERR_NONE;

}