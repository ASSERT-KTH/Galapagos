static inline void csp_rdp_rx_queue_flush(csp_conn_t * conn) {

	/* Loop through RX queue */
	int i, count;
	csp_packet_t * packet;

front:
	count = csp_queue_size(conn->rdp.rx_queue);
	for (i = 0; i < count; i++) {

		if (csp_queue_dequeue_isr(conn->rdp.rx_queue, &packet, &pdTrue) != CSP_QUEUE_OK) {
			csp_log_error("RDP %p: Cannot dequeue from rx_queue in queue deliver", conn);
			break;
		}

		rdp_header_t * header = csp_rdp_header_ref(packet);
		csp_log_protocol("RDP %p: RX Queue deliver matching Element, seq %u", conn, header->seq_nr);

		/* If the matching packet was found: */
		if (header->seq_nr == (uint16_t)(conn->rdp.rcv_cur + 1)) {
			csp_log_protocol("RDP %p: Deliver seq %u", conn, header->seq_nr);
			csp_rdp_receive_data(conn, packet);
			conn->rdp.rcv_cur++;
			/* Loop from first element again */
			goto front;

		/* Otherwise, requeue */
		} else {
			csp_queue_enqueue_isr(conn->rdp.rx_queue, &packet, &pdTrue);
		}

	}

}