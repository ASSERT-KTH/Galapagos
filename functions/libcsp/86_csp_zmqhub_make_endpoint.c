int csp_zmqhub_make_endpoint(const char * host, uint16_t port, char * buf, size_t buf_size) {
	int res = snprintf(buf, buf_size, "tcp://%s:%u", host, port);
	if ((res < 0) || (res >= (int)buf_size)) {
		buf[0] = 0;
		return CSP_ERR_NOMEM;
	}
	return CSP_ERR_NONE;
}