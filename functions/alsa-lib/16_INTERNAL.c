EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_get_subformat)(const snd_pcm_hw_params_t *params, snd_pcm_subformat_t *subformat)
#else
int snd_pcm_hw_params_get_subformat(const snd_pcm_hw_params_t *params, snd_pcm_subformat_t *subformat)
#endif
{
	return snd_pcm_hw_param_get(params, SND_PCM_HW_PARAM_SUBFORMAT, (unsigned int *)subformat, NULL);
}