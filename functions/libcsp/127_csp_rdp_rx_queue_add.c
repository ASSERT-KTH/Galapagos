static inline int csp_rdp_rx_queue_add(csp_conn_t * conn, csp_packet_t * packet, uint16_t seq_nr) {

	if (csp_rdp_seq_in_rx_queue(conn, seq_nr))
		return CSP_QUEUE_ERROR;
	return csp_queue_enqueue_isr(conn->rdp.rx_queue, &packet, &pdTrue);

}