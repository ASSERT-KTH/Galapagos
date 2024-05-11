EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_get_access)(const snd_pcm_hw_params_t *params, snd_pcm_access_t *access)
#else
int snd_pcm_hw_params_get_access(const snd_pcm_hw_params_t *params, snd_pcm_access_t *access)
#endif
{
	unsigned int _val;
	int err = snd_pcm_hw_param_get(params, SND_PCM_HW_PARAM_ACCESS, &_val, NULL);
	if (err >= 0)
		*access = _val;
	return err;
}