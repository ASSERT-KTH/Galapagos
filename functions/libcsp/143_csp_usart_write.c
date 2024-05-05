int csp_usart_write(csp_usart_fd_t fd, const void * data, size_t data_length) {

	if (fd >= 0) {
		int res = write(fd, data, data_length);
		if (res >= 0) {
			return res;
		}
	}
	return CSP_ERR_TX; // best matching CSP error code.

}