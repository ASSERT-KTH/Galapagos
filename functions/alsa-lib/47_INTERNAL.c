EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_set_periods_first)(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
#else
int snd_pcm_hw_params_set_periods_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
#endif
{
	return snd_pcm_hw_param_set_first(pcm, params, SND_PCM_HW_PARAM_PERIODS, val, dir);
}