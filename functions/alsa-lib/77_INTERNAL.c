EXPORT_SYMBOL int INTERNAL(snd_timer_params_set_exclusive)(snd_timer_params_t * params, int exclusive)
#else
int snd_timer_params_set_exclusive(snd_timer_params_t * params, int exclusive)
#endif
{
	assert(params);
	if (exclusive)
		params->flags |= SNDRV_TIMER_PSFLG_EXCLUSIVE;
	else
		params->flags &= ~SNDRV_TIMER_PSFLG_EXCLUSIVE;
	return 0;
}