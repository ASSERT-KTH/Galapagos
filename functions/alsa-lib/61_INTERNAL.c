EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_get_tick_time)(const snd_pcm_hw_params_t *params ATTRIBUTE_UNUSED, unsigned int *val, int *dir ATTRIBUTE_UNUSED)
#else
int snd_pcm_hw_params_get_tick_time(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
#endif
{
	*val = 0;
	return 0;
}