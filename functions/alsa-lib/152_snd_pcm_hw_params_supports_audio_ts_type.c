int snd_pcm_hw_params_supports_audio_ts_type(const snd_pcm_hw_params_t *params, int type)
{
	assert(params);
	if (CHECK_SANITY(params->info == ~0U)) {
		SNDMSG("invalid PCM info field");
		return 0; /* FIXME: should be a negative error? */
	}
	switch (type) {
	case SNDRV_PCM_AUDIO_TSTAMP_TYPE_COMPAT:
		return !!(params->info & SNDRV_PCM_INFO_HAS_WALL_CLOCK); /* deprecated */
	case SNDRV_PCM_AUDIO_TSTAMP_TYPE_DEFAULT:
		return 1; /* always supported, based on hw_ptr */
	case SNDRV_PCM_AUDIO_TSTAMP_TYPE_LINK:
		return !!(params->info & SNDRV_PCM_INFO_HAS_LINK_ATIME);
	case SNDRV_PCM_AUDIO_TSTAMP_TYPE_LINK_ABSOLUTE:
		return !!(params->info & SNDRV_PCM_INFO_HAS_LINK_ABSOLUTE_ATIME);
	case SNDRV_PCM_AUDIO_TSTAMP_TYPE_LINK_ESTIMATED:
		return !!(params->info & SNDRV_PCM_INFO_HAS_LINK_ESTIMATED_ATIME);
	case SNDRV_PCM_AUDIO_TSTAMP_TYPE_LINK_SYNCHRONIZED:
		return !!(params->info & SNDRV_PCM_INFO_HAS_LINK_SYNCHRONIZED_ATIME);
	default:
		return 0;
	}
}