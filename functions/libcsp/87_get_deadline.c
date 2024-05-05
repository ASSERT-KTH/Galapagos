static inline int get_deadline(struct timespec *ts, uint32_t timeout_ms)
{
	int ret = clock_gettime(CLOCK_MONOTONIC, ts);

	if (ret < 0) {
		return ret;
	}

	uint32_t sec = timeout_ms / 1000;
	uint32_t nsec = (timeout_ms - 1000 * sec) * 1000000;

	ts->tv_sec += sec;

	if (ts->tv_nsec + nsec >= 1000000000) {
		ts->tv_sec++;
	}

	ts->tv_nsec = (ts->tv_nsec + nsec) % 1000000000;

	return ret;
}