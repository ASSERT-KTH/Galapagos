static inline bool csp_rdp_should_ack(csp_conn_t * conn) {

	/* If delayed ACKs are not used, always ACK */
	if (!conn->rdp.delayed_acks) {
		return true;
	}

	/* ACK if time since last ACK is greater than ACK timeout */
	uint32_t time_now = csp_get_ms();
	if (csp_rdp_time_after(time_now, conn->rdp.ack_timestamp + conn->rdp.ack_timeout))
		return true;

	/* ACK if number of unacknowledged packets is greater than delay count */
	if (csp_rdp_seq_after(conn->rdp.rcv_cur, conn->rdp.rcv_lsa + conn->rdp.ack_delay_count))
		return true;

	return false;

}