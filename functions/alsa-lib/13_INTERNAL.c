EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_get_format)(const snd_pcm_hw_params_t *params, snd_pcm_format_t *format)
#else
int snd_pcm_hw_params_get_format(const snd_pcm_hw_params_t *params, snd_pcm_format_t *format)
#endif
{
	return snd_pcm_hw_param_get(params, SND_PCM_HW_PARAM_FORMAT, (unsigned int *)format, NULL);
}