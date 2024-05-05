int csp_send(csp_conn_t * conn, csp_packet_t * packet, uint32_t timeout) {

	if ((conn == NULL) || (packet == NULL) || (conn->state != CONN_OPEN)) {
		csp_log_error("Invalid call to csp_send");
		return 0;
	}

#if (CSP_USE_RDP)
	if (conn->idout.flags & CSP_FRDP) {
		if (csp_rdp_send(conn, packet) != CSP_ERR_NONE) {
			return 0;
		}
	}
#endif

	int ret = csp_send_direct(conn->idout, packet, csp_rtable_find_route(conn->idout.dst), timeout);

	return (ret == CSP_ERR_NONE) ? 1 : 0;

}