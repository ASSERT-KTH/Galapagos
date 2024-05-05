static int kiss_driver_tx(void *driver_data, const unsigned char * data, size_t data_length) {

	kiss_context_t * ctx = driver_data;
	if (csp_usart_write(ctx->fd, data, data_length) == (int) data_length) {
		return CSP_ERR_NONE;
	}
	return CSP_ERR_TX;
}