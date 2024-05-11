EXPORT_SYMBOL int INTERNAL(snd_timer_params_get_exclusive)(snd_timer_params_t * params)
#else
int snd_timer_params_get_exclusive(snd_timer_params_t * params)
#endif
{
	assert(params);
	return params->flags & SNDRV_TIMER_PSFLG_EXCLUSIVE ? 1 : 0;
}