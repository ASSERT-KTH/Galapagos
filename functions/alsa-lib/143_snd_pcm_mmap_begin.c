int snd_pcm_mmap_begin(snd_pcm_t *pcm,
		       const snd_pcm_channel_area_t **areas,
		       snd_pcm_uframes_t *offset,
		       snd_pcm_uframes_t *frames)
{
	int err;

	err = bad_pcm_state(pcm, P_STATE_RUNNABLE, 0);
	if (err < 0)
		return err;
	snd_pcm_lock(pcm->fast_op_arg);
	err = __snd_pcm_mmap_begin(pcm, areas, offset, frames);
	snd_pcm_unlock(pcm->fast_op_arg);
	return err;
}