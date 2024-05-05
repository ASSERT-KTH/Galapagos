void csp_rdp_flush_all(csp_conn_t * conn) {

	if ((conn == NULL) || conn->rdp.tx_queue == NULL) {
		csp_log_error("RDP %p: Null pointer passed to rdp flush all", conn);
		return;
	}

	rdp_packet_t * packet;

	/* Empty TX queue */
	while (csp_queue_dequeue_isr(conn->rdp.tx_queue, &packet, &pdTrue) == CSP_QUEUE_OK) {
		if (packet != NULL) {
			csp_log_protocol("RDP %p: Flush TX Element, time %"PRIu32", seq %u", conn, packet->timestamp, csp_ntoh16(csp_rdp_header_ref((csp_packet_t *) packet)->seq_nr));
			csp_buffer_free(packet);
		}
	}

	/* Empty RX queue */
	while (csp_queue_dequeue_isr(conn->rdp.rx_queue, &packet, &pdTrue) == CSP_QUEUE_OK) {
		if (packet != NULL) {
			csp_log_protocol("RDP %p: Flush RX Element, time %"PRIu32", seq %u", conn, packet->timestamp, csp_ntoh16(csp_rdp_header_ref((csp_packet_t *) packet)->seq_nr));
			csp_buffer_free(packet);
		}
	}

}