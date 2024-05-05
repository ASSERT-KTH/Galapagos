int csp_rdp_check_ack(csp_conn_t * conn) {

	/* Check all RX queues for spare capacity */
	int avail = 1;
	for (int prio = 0; prio < CSP_RX_QUEUES; prio++) {
		if (csp_conf.conn_queue_length - csp_queue_size(conn->rx_queue[prio]) <= 2 * (int32_t)conn->rdp.window_size) {
			avail = 0;
			break;
		}
	}

	/* If more space available, only send after ack timeout or immediately if delay_acks is zero */
	if (avail && csp_rdp_should_ack(conn)) {
		csp_rdp_send_cmp(conn, NULL, RDP_ACK, conn->rdp.snd_nxt, conn->rdp.rcv_cur);
	}

	return CSP_ERR_NONE;

}