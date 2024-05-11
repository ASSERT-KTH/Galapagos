static inline int hw_is_mask(snd_pcm_hw_param_t var)
{
#if SND_PCM_HW_PARAM_FIRST_MASK == 0
	return var <= SND_PCM_HW_PARAM_LAST_MASK;
#else
	return var >= SND_PCM_HW_PARAM_FIRST_MASK &&
		var <= SND_PCM_HW_PARAM_LAST_MASK;
#endif
}