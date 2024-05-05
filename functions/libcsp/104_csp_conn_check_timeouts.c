void csp_conn_check_timeouts(void) {
#if (CSP_USE_RDP)
	for (int i = 0; i < csp_conf.conn_max; i++) {
		if (arr_conn[i].state == CONN_OPEN) {
			if (arr_conn[i].idin.flags & CSP_FRDP) {
				csp_rdp_check_timeouts(&arr_conn[i]);
			}
		}
	}
#endif
}