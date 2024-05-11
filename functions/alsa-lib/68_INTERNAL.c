EXPORT_SYMBOL int INTERNAL(snd_pcm_sw_params_get_sleep_min)(const snd_pcm_sw_params_t *params ATTRIBUTE_UNUSED, unsigned int *val)
#else
int snd_pcm_sw_params_get_sleep_min(const snd_pcm_sw_params_t *params, unsigned int *val)
#endif
{
	*val = 0;
	return 0;
}