EXPORT_SYMBOL int INTERNAL(snd_pcm_sw_params_get_stop_threshold)(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val)
#else
int snd_pcm_sw_params_get_stop_threshold(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val)
#endif
{
	assert(params);
	*val = params->stop_threshold;
	return 0;
}