void snd_pcm_free_chmaps(snd_pcm_chmap_query_t **maps)
{
	snd_pcm_chmap_query_t **p;
	if (!maps)
		return;
	for (p = maps; *p; p++)
		free(*p);
	free(maps);
}