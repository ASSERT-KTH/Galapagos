static inline void gettimestamp(snd_htimestamp_t *tstamp,
				snd_pcm_tstamp_type_t tstamp_type)
{
	clockid_t id;

	switch (tstamp_type) {
#ifdef CLOCK_MONOTONIC_RAW
	case SND_PCM_TSTAMP_TYPE_MONOTONIC_RAW:
		id = CLOCK_MONOTONIC_RAW;
		break;
#endif
#ifdef CLOCK_MONOTONIC
	case SND_PCM_TSTAMP_TYPE_MONOTONIC:
		id = CLOCK_MONOTONIC;
		break;
#endif
	default:
		id = CLOCK_REALTIME;
		break;
	}
	clock_gettime(id, tstamp);
}