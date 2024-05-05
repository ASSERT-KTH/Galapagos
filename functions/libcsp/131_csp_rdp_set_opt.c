void csp_rdp_set_opt(unsigned int window_size, unsigned int conn_timeout_ms,
		unsigned int packet_timeout_ms, unsigned int delayed_acks,
		unsigned int ack_timeout, unsigned int ack_delay_count) {
	csp_rdp_window_size = window_size;
	csp_rdp_conn_timeout = conn_timeout_ms;
	csp_rdp_packet_timeout = packet_timeout_ms;
	csp_rdp_delayed_acks = delayed_acks;
	csp_rdp_ack_timeout = ack_timeout;
	csp_rdp_ack_delay_count = ack_delay_count;
}