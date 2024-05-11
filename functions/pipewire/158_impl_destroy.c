static void impl_destroy(struct impl *impl)
{
	sink_destroy(impl);

	if (impl->registry) {
		spa_hook_remove(&impl->registry_listener);
		pw_proxy_destroy((struct pw_proxy*)impl->registry);
		impl->registry = NULL;
	}

	if (impl->core) {
		spa_hook_remove(&impl->core_listener);
		spa_hook_remove(&impl->core_proxy_listener);
		if (impl->do_disconnect)
			pw_core_disconnect(impl->core);
		impl->core = NULL;
	}

	if (impl->properties) {
		pw_properties_free(impl->properties);
		impl->properties = NULL;
	}

	bitmap_free(&impl->sink_ids);
	bitmap_free(&impl->fallback_sink_ids);

	free(impl);
}