int snd_pcm_start(snd_pcm_t *pcm)
{
	int err;

	assert(pcm);
	if (CHECK_SANITY(! pcm->setup)) {
		SNDMSG("PCM not set up");
		return -EIO;
	}
	err = bad_pcm_state(pcm, P_STATE(PREPARED), 0);
	if (err < 0)
		return err;
	snd_pcm_lock(pcm->fast_op_arg);
	err = __snd_pcm_start(pcm);
	snd_pcm_unlock(pcm->fast_op_arg);
	return err;
}