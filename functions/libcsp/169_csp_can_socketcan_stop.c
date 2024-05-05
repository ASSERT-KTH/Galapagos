int csp_can_socketcan_stop(csp_iface_t *iface)
{
	can_context_t * ctx = iface->driver_data;

	int error = pthread_cancel(ctx->rx_thread);
	if (error != 0) {
		csp_log_error("%s[%s]: pthread_cancel() failed, error: %s", __FUNCTION__, ctx->name, strerror(errno));
		return CSP_ERR_DRIVER;
	}
	error = pthread_join(ctx->rx_thread, NULL);
	if (error != 0) {
		csp_log_error("%s[%s]: pthread_join() failed, error: %s", __FUNCTION__, ctx->name, strerror(errno));
		return CSP_ERR_DRIVER;
	}
        socketcan_free(ctx);
	return CSP_ERR_NONE;
}