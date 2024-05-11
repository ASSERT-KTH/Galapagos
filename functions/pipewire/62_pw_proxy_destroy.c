void pw_proxy_destroy(struct pw_proxy *proxy)
{
	pw_log_debug("%p: destroy id:%u removed:%u zombie:%u ref:%d", proxy,
			proxy->id, proxy->removed, proxy->zombie, proxy->refcount);

	assert(!proxy->destroyed);
	proxy->destroyed = true;

	if (!proxy->removed) {
		/* if the server did not remove this proxy, schedule a
		 * destroy if we can */
		if (proxy->core && !proxy->core->removed) {
			pw_core_destroy(proxy->core, proxy);
			proxy->refcount++;
		} else {
			proxy->removed = true;
		}
	}
	if (proxy->removed)
		remove_from_map(proxy);

	if (!proxy->zombie) {
		/* mark zombie and emit destroyed. No more
		 * events will be emitted on zombie objects */
		proxy->zombie = true;
		pw_proxy_emit_destroy(proxy);
	}

	pw_proxy_unref(proxy);
}