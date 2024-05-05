static inline bool csp_rdp_seq_in_rx_queue(csp_conn_t * conn, uint16_t seq_nr) {

	/* Loop through RX queue */
	int i, count;
	rdp_packet_t * packet;
	count = csp_queue_size(conn->rdp.rx_queue);
	for (i = 0; i < count; i++) {

		if (csp_queue_dequeue_isr(conn->rdp.rx_queue, &packet, &pdTrue) != CSP_QUEUE_OK) {
			csp_log_error("RDP %p: Cannot dequeue from rx_queue in queue exists", conn);
			break;
		}

		csp_queue_enqueue_isr(conn->rdp.rx_queue, &packet, &pdTrue);

		rdp_header_t * header = csp_rdp_header_ref((csp_packet_t *) packet);
		csp_log_protocol("RDP %p: RX Queue exists matching Element, seq %u", conn, header->seq_nr);

		/* If the matching packet was found, deliver */
		if (header->seq_nr == seq_nr) {
                    csp_log_protocol("RDP %p: We have a match", conn);
			return true;
		}

	}

	return false;

}