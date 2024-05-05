__attribute__((weak)) int csp_clock_set_time(const csp_timestamp_t * time) {

	struct timespec ts = {.tv_sec = time->tv_sec, .tv_nsec = time->tv_nsec};
	if (clock_settime(CLOCK_REALTIME, &ts) == 0) {
		return CSP_ERR_NONE;
	}
	return CSP_ERR_INVAL; // CSP doesn't have any matching error codes

}