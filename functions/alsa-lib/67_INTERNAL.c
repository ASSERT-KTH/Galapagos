EXPORT_SYMBOL int INTERNAL(snd_pcm_sw_params_get_tstamp_mode)(const snd_pcm_sw_params_t *params, snd_pcm_tstamp_t *val)
#else
int snd_pcm_sw_params_get_tstamp_mode(const snd_pcm_sw_params_t *params, snd_pcm_tstamp_t *val)
#endif
{
	assert(params && val);
	*val = params->tstamp_mode;
	return 0;
}