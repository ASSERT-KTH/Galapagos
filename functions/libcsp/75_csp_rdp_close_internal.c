static int csp_rdp_close_internal(csp_conn_t * conn, uint8_t closed_by, bool send_rst) {

	if (conn->rdp.state == RDP_CLOSED) {
		return CSP_ERR_NONE;
	}

	conn->rdp.closed_by |= closed_by;

	/* If connection is open, send reset */
	if (conn->rdp.state != RDP_CLOSE_WAIT) {
		conn->rdp.state = RDP_CLOSE_WAIT;
		conn->timestamp = csp_get_ms();
		if (send_rst) {
			csp_rdp_send_cmp(conn, NULL, RDP_ACK | RDP_RST, conn->rdp.snd_nxt, conn->rdp.rcv_cur);
		}
		csp_log_protocol("RDP %p: csp_rdp_close(0x%x)%s -> CLOSE_WAIT", conn, closed_by, send_rst ? ", sent RST" : "");
		csp_bin_sem_post(&conn->rdp.tx_wait); // wake up any pendng Tx
	}

	if (conn->rdp.closed_by != CSP_RDP_CLOSED_BY_ALL) {
		csp_log_protocol("RDP %p: csp_rdp_close(0x%x), waiting for:%s%s%s",
			conn, closed_by,
			(conn->rdp.closed_by & CSP_RDP_CLOSED_BY_USERSPACE) ? "" : " userspace",
			(conn->rdp.closed_by & CSP_RDP_CLOSED_BY_PROTOCOL) ? "" : " protocol",
			(conn->rdp.closed_by & CSP_RDP_CLOSED_BY_TIMEOUT) ? "" : " timeout");
		return CSP_ERR_AGAIN;
        }

        csp_log_protocol("RDP %p: csp_rdp_close(0x%x) -> CLOSED", conn, closed_by);
	conn->rdp.state = RDP_CLOSED;
        conn->rdp.closed_by = 0;
	return CSP_ERR_NONE;

}