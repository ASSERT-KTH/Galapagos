int snd_pcm_close(snd_pcm_t *pcm)
{
	int res = 0, err;
	assert(pcm);
	if (pcm->setup && !pcm->donot_close) {
		snd_pcm_drop(pcm);
		err = snd_pcm_hw_free(pcm);
		if (err < 0)
			res = err;
	}
	if (pcm->mmap_channels)
		snd_pcm_munmap(pcm);
	while (!list_empty(&pcm->async_handlers)) {
		snd_async_handler_t *h = list_entry(pcm->async_handlers.next, snd_async_handler_t, hlist);
		snd_async_del_handler(h);
	}
	if (pcm->ops->close)
		err = pcm->ops->close(pcm->op_arg);
	else
		err = -ENOSYS;
	if (err < 0)
		res = err;
	err = snd_pcm_free(pcm);
	if (err < 0)
		res = err;
	return res;
}	