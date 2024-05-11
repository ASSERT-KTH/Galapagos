EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_get_period_time_max)(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
#else
int snd_pcm_hw_params_get_period_time_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
#endif
{
	return snd_pcm_hw_param_get_max(params, SND_PCM_HW_PARAM_PERIOD_TIME, val, dir);
}