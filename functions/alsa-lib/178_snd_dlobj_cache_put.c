int snd_dlobj_cache_put(void *func)
{
	struct list_head *p;
	struct dlobj_cache *c;
	unsigned int refcnt;

	if (!func)
		return -ENOENT;

	snd_dlobj_lock();
	list_for_each(p, &pcm_dlobj_list) {
		c = list_entry(p, struct dlobj_cache, list);
		if (c->func == func) {
			refcnt = c->refcnt;
			if (c->refcnt > 0)
				c->refcnt--;
			snd_dlobj_unlock();
			return refcnt == 1 ? 0 : -EINVAL;
		}
	}
	snd_dlobj_unlock();
	return -ENOENT;
}