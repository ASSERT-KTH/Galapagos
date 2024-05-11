EXPORT_SYMBOL void INTERNAL(snd_timer_params_set_filter)(snd_timer_params_t * params, unsigned int filter)
#else
void snd_timer_params_set_filter(snd_timer_params_t * params, unsigned int filter)
#endif
{
	assert(params);
	params->filter = filter;
}