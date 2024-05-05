int csp_transaction_w_opts(uint8_t prio, uint8_t dest, uint8_t port, uint32_t timeout, void * outbuf, int outlen, void * inbuf, int inlen, uint32_t opts) {

	csp_conn_t * conn = csp_connect(prio, dest, port, 0, opts);
	if (conn == NULL)
		return 0;

	int status = csp_transaction_persistent(conn, timeout, outbuf, outlen, inbuf, inlen);

	csp_close(conn);

	return status;

}