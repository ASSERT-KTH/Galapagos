void csp_free_resources(void) {

	csp_rtable_free();
	csp_qfifo_free_resources();
	csp_port_free_resources();
	csp_conn_free_resources();
	csp_buffer_free_resources();
	memset(&csp_conf, 0, sizeof(csp_conf));

}