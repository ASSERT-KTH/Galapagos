static inline void gettimestamp(snd_htimestamp_t *tstamp,
				snd_pcm_tstamp_type_t tstamp_type)
{
	struct timeval tv;

	gettimeofday(&tv, 0);
	tstamp->tv_sec = tv.tv_sec;
	tstamp->tv_nsec = tv.tv_usec * 1000L;
}