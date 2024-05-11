EXPORT_SYMBOL int INTERNAL(snd_pcm_hw_params_set_tick_time_near)(snd_pcm_t *pcm ATTRIBUTE_UNUSED, snd_pcm_hw_params_t *params ATTRIBUTE_UNUSED, unsigned int *val ATTRIBUTE_UNUSED, int *dir ATTRIBUTE_UNUSED)
#else
int snd_pcm_hw_params_set_tick_time_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir)
#endif
{
	return 0;
}