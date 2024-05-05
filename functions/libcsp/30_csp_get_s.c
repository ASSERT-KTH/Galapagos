uint32_t csp_get_s(void) {

	struct timespec ts;
	if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0) {
		return (uint32_t)ts.tv_sec;
	}
	return 0;

}