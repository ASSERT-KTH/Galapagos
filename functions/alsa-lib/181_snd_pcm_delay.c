int snd_pcm_delay(snd_pcm_t *pcm, snd_pcm_sframes_t *delayp)
{
	int err;

	assert(pcm);
	if (CHECK_SANITY(! pcm->setup)) {
		SNDMSG("PCM not set up");
		return -EIO;
	}
	snd_pcm_lock(pcm->fast_op_arg);
	err = __snd_pcm_delay(pcm, delayp);
	snd_pcm_unlock(pcm->fast_op_arg);
	return err;
}