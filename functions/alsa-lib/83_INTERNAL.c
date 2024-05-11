EXPORT_SYMBOL int INTERNAL(snd_timer_query_status)(snd_timer_query_t *timer, snd_timer_gstatus_t *status)
#else
int snd_timer_query_status(snd_timer_query_t *timer, snd_timer_gstatus_t *status)
#endif
{
  	assert(timer);
  	assert(status);
	return timer->ops->status(timer, status);
}