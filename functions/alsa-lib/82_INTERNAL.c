EXPORT_SYMBOL int INTERNAL(snd_timer_query_params)(snd_timer_query_t *timer, snd_timer_gparams_t *params)
#else
int snd_timer_query_params(snd_timer_query_t *timer, snd_timer_gparams_t *params)
#endif
{
  	assert(timer);
  	assert(params);
	return timer->ops->params(timer, params);
}