int snd_pcm_hw_free(snd_pcm_t *pcm)
{
	int err;
	if (! pcm->setup)
		return 0;
	if (pcm->mmap_channels) {
		err = snd_pcm_munmap(pcm);
		if (err < 0)
			return err;
	}
	// assert(snd_pcm_state(pcm) == SND_PCM_STATE_SETUP ||
	//        snd_pcm_state(pcm) == SND_PCM_STATE_PREPARED);
	if (pcm->ops->hw_free)
		err = pcm->ops->hw_free(pcm->op_arg);
	else
		err = -ENOSYS;
	pcm->setup = 0;
	if (err < 0)
		return err;
	return 0;
}