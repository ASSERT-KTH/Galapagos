EXPORT_SYMBOL void INTERNAL(snd_pcm_status_get_trigger_htstamp)(const snd_pcm_status_t *obj, snd_htimestamp_t *ptr)
#else
void snd_pcm_status_get_trigger_htstamp(const snd_pcm_status_t *obj, snd_htimestamp_t *ptr)
#endif
{
	assert(obj && ptr);
	*ptr = obj->trigger_tstamp;
}