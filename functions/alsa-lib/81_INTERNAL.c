EXPORT_SYMBOL int INTERNAL(snd_timer_query_info)(snd_timer_query_t *timer, snd_timer_ginfo_t *info)
#else
int snd_timer_query_info(snd_timer_query_t *timer, snd_timer_ginfo_t *info)
#endif
{
  	assert(timer);
  	assert(info);
	return timer->ops->info(timer, info);
}