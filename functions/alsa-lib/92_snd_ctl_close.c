int snd_ctl_close(snd_ctl_t *ctl)
{
	int err;
	while (!list_empty(&ctl->async_handlers)) {
		snd_async_handler_t *h = list_entry(&ctl->async_handlers.next, snd_async_handler_t, hlist);
		snd_async_del_handler(h);
	}
	err = ctl->ops->close(ctl);
	free(ctl->name);
	snd_dlobj_cache_put(ctl->open_func);
	free(ctl);
	return err;
}