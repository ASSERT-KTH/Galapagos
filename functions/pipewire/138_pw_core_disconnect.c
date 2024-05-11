int pw_core_disconnect(struct pw_core *core)
{
	/*
	 * the `proxy` member must be the first because the whole pw_core object is
	 * freed via the free() call in pw_proxy_destroy() -> pw_proxy_unref()
	 */
	SPA_STATIC_ASSERT(offsetof(struct pw_core, proxy) == 0, "`proxy` member must be first");

	pw_log_debug("%p: disconnect", core);
	if (!core->removed)
		pw_proxy_remove(&core->proxy);
	if (!core->destroyed)
		pw_proxy_destroy(&core->proxy);
	return 0;
}