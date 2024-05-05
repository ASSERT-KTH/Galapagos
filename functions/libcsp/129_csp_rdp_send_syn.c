static int csp_rdp_send_syn(csp_conn_t * conn) {

	/* Allocate message */
	csp_packet_t * packet = csp_buffer_get(100);
	if (packet == NULL) return CSP_ERR_NOMEM;

	/* Generate contents */
	packet->data32[0] = csp_hton32(csp_rdp_window_size);
	packet->data32[1] = csp_hton32(csp_rdp_conn_timeout);
	packet->data32[2] = csp_hton32(csp_rdp_packet_timeout);
	packet->data32[3] = csp_hton32(csp_rdp_delayed_acks);
	packet->data32[4] = csp_hton32(csp_rdp_ack_timeout);
	packet->data32[5] = csp_hton32(csp_rdp_ack_delay_count);
	packet->length = 6 * sizeof(uint32_t);

	return csp_rdp_send_cmp(conn, packet, RDP_SYN, conn->rdp.snd_iss, 0);

}