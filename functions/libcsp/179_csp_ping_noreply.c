void csp_ping_noreply(uint8_t node) {

	/* Prepare data */
	csp_packet_t * packet = csp_buffer_get(1);
	if (packet == NULL)
		return;

	/* Open connection */
	csp_conn_t * conn = csp_connect(CSP_PRIO_NORM, node, CSP_PING, 0, 0);
	if (conn == NULL) {
		csp_buffer_free(packet);
		return;
	}

	packet->data[0] = 0x55;
	packet->length = 1;

	printf("Ping ignore reply node %u.\r\n", (unsigned int) node);

	/* Try to send frame */
	if (!csp_send(conn, packet, 0))
		csp_buffer_free(packet);

	csp_close(conn);

}