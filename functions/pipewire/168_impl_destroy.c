static void impl_destroy(struct impl *impl)
{
	impl->stopping = true;

	cleanup_streams(impl);

	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);

	pw_loop_invoke(impl->main_loop, NULL, 0, NULL, 0, false, impl);

	pw_properties_free(impl->stream_props);
	pw_properties_free(impl->props);

	if (impl->timer)
		pw_loop_destroy_source(impl->main_loop, impl->timer);

	free(impl->buffer);
	free(impl);
}