EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_get_period_size_min)(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir)
#else
int snd_pcm_hw_params_get_period_size_min(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir)
#endif
{
	unsigned int _val = *val;
	int err = snd_pcm_hw_param_get_min(params, SND_PCM_HW_PARAM_PERIOD_SIZE, &_val, dir);
	if (err >= 0)
		*val = _val;
	return err;
}