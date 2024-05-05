uint32_t csp_get_ms(void) {

	struct timespec ts;
	if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0) {
		return (uint32_t)((ts.tv_sec*1000) + (ts.tv_nsec/1000000));
	}
	return 0;

}