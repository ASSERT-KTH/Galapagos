EXPORT_SYMBOL const char *INTERNAL(snd_pcm_type_name)(snd_pcm_type_t type)
#else
const char *snd_pcm_type_name(snd_pcm_type_t type)
#endif
{
	if (type > SND_PCM_TYPE_LAST)
		return NULL;
	return snd_pcm_type_names[type];
}