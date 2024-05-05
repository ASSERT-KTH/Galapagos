static int csp_rdp_send_eack(csp_conn_t * conn) {

	/* Allocate message */
	csp_packet_t * packet_eack = csp_buffer_get(100);
	if (packet_eack == NULL) return CSP_ERR_NOMEM;
	packet_eack->length = 0;

	/* Loop through RX queue */
	int i, count;
	csp_packet_t * packet;
	count = csp_queue_size(conn->rdp.rx_queue);
	for (i = 0; i < count; i++) {

		if (csp_queue_dequeue_isr(conn->rdp.rx_queue, &packet, &pdTrue) != CSP_QUEUE_OK) {
			csp_log_error("RDP %p: Cannot dequeue from rx_queue in queue deliver", conn);
			break;
		}

		/* Add seq nr to EACK packet */
		rdp_header_t * header = csp_rdp_header_ref(packet);
		packet_eack->data16[packet_eack->length/sizeof(uint16_t)] = csp_hton16(header->seq_nr);
		packet_eack->length += sizeof(uint16_t);
		csp_log_protocol("RDP %p: Added EACK nr %u", conn, header->seq_nr);

		/* Requeue */
		csp_queue_enqueue_isr(conn->rdp.rx_queue, &packet, &pdTrue);

	}

	return csp_rdp_send_cmp(conn, packet_eack, RDP_ACK | RDP_EAK, conn->rdp.snd_nxt, conn->rdp.rcv_cur);

}