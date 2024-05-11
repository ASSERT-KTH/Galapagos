EXPORT_SYMBOL unsigned int INTERNAL(snd_timer_params_get_filter)(snd_timer_params_t * params)
#else
unsigned int snd_timer_params_get_filter(snd_timer_params_t * params)
#endif
{
	assert(params);
	return params->filter;
}