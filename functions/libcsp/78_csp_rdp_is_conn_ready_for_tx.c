static inline bool csp_rdp_is_conn_ready_for_tx(csp_conn_t * conn)
{
	// Check Tx window (messages waiting for acks)
	if (csp_rdp_seq_after(conn->rdp.snd_nxt, conn->rdp.snd_una + conn->rdp.window_size - 1)) {
		return false;
	}
	return true;
}