int snd_pcm_free(snd_pcm_t *pcm)
{
	assert(pcm);
	free(pcm->name);
	free(pcm->hw.link_dst);
	free(pcm->appl.link_dst);
	snd_dlobj_cache_put(pcm->open_func);
#ifdef THREAD_SAFE_API
	pthread_mutex_destroy(&pcm->lock);
#endif
	free(pcm);
	return 0;
}