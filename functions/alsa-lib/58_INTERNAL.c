EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_set_buffer_size_near)(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val)
#else
int snd_pcm_hw_params_set_buffer_size_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val)
#endif
{
	unsigned int _val = *val;
	int err = snd_pcm_hw_param_set_near(pcm, params, SND_PCM_HW_PARAM_BUFFER_SIZE, &_val, NULL);
	if (err >= 0)
		*val = _val;
	return err;
}