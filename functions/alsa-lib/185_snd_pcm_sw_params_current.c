int snd_pcm_sw_params_current(snd_pcm_t *pcm, snd_pcm_sw_params_t *params)
{
	assert(pcm && params);
	if (CHECK_SANITY(! pcm->setup)) {
		SNDMSG("PCM not set up");
		return -EIO;
	}
	__snd_pcm_lock(pcm); /* forced lock due to pcm field changes */
	snd_pcm_sw_params_current_no_lock(pcm, params);
	__snd_pcm_unlock(pcm);
	return 0;
}