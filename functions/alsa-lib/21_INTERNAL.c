EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_get_channels_max)(const snd_pcm_hw_params_t *params, unsigned int *val)
#else
int snd_pcm_hw_params_get_channels_max(const snd_pcm_hw_params_t *params, unsigned int *val)
#endif
{
	return snd_pcm_hw_param_get_max(params, SND_PCM_HW_PARAM_CHANNELS, val, NULL);
}