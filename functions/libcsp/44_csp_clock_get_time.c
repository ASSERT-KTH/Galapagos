__attribute__((weak)) void csp_clock_get_time(csp_timestamp_t * time) {

	struct timespec ts;
	if (clock_gettime(CLOCK_REALTIME, &ts) == 0) {
		time->tv_sec = ts.tv_sec;
		time->tv_nsec = ts.tv_nsec;
	} else {
		time->tv_sec = 0;
		time->tv_nsec = 0;
	}
}