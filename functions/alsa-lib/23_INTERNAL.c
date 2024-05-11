EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_set_channels_first)(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val)
#else
int snd_pcm_hw_params_set_channels_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val)
#endif
{
	return snd_pcm_hw_param_set_first(pcm, params, SND_PCM_HW_PARAM_CHANNELS, val, NULL);
}