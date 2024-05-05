static inline int init_cond_clock_monotonic(pthread_cond_t * cond)
{

	int ret;
	pthread_condattr_t attr;

	pthread_condattr_init(&attr);
	ret = pthread_condattr_setclock(&attr, CLOCK_MONOTONIC);

	if (ret == 0) {
		ret = pthread_cond_init(cond, &attr);
	}

	pthread_condattr_destroy(&attr);
	return ret;

}