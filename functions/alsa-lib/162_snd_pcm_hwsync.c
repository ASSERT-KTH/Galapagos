int snd_pcm_hwsync(snd_pcm_t *pcm)
{
	int err;

	assert(pcm);
	if (CHECK_SANITY(! pcm->setup)) {
		SNDMSG("PCM not set up");
		return -EIO;
	}
	snd_pcm_lock(pcm->fast_op_arg);
	err = __snd_pcm_hwsync(pcm);
	snd_pcm_unlock(pcm->fast_op_arg);
	return err;
}