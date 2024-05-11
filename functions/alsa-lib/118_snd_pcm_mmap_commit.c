snd_pcm_sframes_t snd_pcm_mmap_commit(snd_pcm_t *pcm,
				      snd_pcm_uframes_t offset,
				      snd_pcm_uframes_t frames)
{
	snd_pcm_sframes_t result;
	int err;

	err = bad_pcm_state(pcm, P_STATE_RUNNABLE, 0);
	if (err < 0)
		return err;
	snd_pcm_lock(pcm->fast_op_arg);
	result = __snd_pcm_mmap_commit(pcm, offset, frames);
	snd_pcm_unlock(pcm->fast_op_arg);
	return result;
}