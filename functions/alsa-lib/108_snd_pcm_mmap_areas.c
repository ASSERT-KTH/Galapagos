static inline const snd_pcm_channel_area_t *snd_pcm_mmap_areas(snd_pcm_t *pcm)
{
	if (pcm->stopped_areas &&
	    __snd_pcm_state(pcm) != SND_PCM_STATE_RUNNING)
		return pcm->stopped_areas;
	return pcm->running_areas;
}