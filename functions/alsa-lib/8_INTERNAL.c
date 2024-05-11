EXPORT_SYMBOL snd_pcm_sframes_t INTERNAL(snd_pcm_forward)(snd_pcm_t *pcm, snd_pcm_uframes_t frames)
#else
snd_pcm_sframes_t snd_pcm_forward(snd_pcm_t *pcm, snd_pcm_uframes_t frames)
#endif
{
	snd_pcm_sframes_t result;
	int err;

	assert(pcm);
	if (CHECK_SANITY(! pcm->setup)) {
		SNDMSG("PCM not set up");
		return -EIO;
	}
	if (frames == 0)
		return 0;
	err = bad_pcm_state(pcm, P_STATE_RUNNABLE, 0);
	if (err < 0)
		return err;
	snd_pcm_lock(pcm->fast_op_arg);
	if (pcm->fast_ops->forward)
		result = pcm->fast_ops->forward(pcm->fast_op_arg, frames);
	else
		result = -ENOSYS;
	snd_pcm_unlock(pcm->fast_op_arg);
	return result;
}