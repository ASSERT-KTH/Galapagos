EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_get_buffer_size)(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val)
#else
int snd_pcm_hw_params_get_buffer_size(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val)
#endif
{
	unsigned int _val;
	int err = snd_pcm_hw_param_get(params, SND_PCM_HW_PARAM_BUFFER_SIZE, &_val, NULL);
	if (err >= 0)
		*val = _val;
	return err;
}