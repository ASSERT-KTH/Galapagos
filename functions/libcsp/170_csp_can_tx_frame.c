static int csp_can_tx_frame(void * driver_data, uint32_t id, const uint8_t * data, uint8_t dlc)
{
	if (dlc > 8) {
		return CSP_ERR_INVAL;
	}

	struct can_frame frame = {.can_id = id | CAN_EFF_FLAG,
                                  .can_dlc = dlc};
        memcpy(frame.data, data, dlc);

	uint32_t elapsed_ms = 0;
        can_context_t * ctx = driver_data;
	while (write(ctx->socket, &frame, sizeof(frame)) != sizeof(frame)) {
		if ((errno != ENOBUFS) || (elapsed_ms >= 1000)) {
			csp_log_warn("%s[%s]: write() failed, errno %d: %s", __FUNCTION__, ctx->name, errno, strerror(errno));
			return CSP_ERR_TX;
		}
		csp_sleep_ms(5);
		elapsed_ms += 5;
	}

	return CSP_ERR_NONE;
}