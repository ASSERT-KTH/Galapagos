static void impl_destroy(struct impl *impl)
{
	if (impl->stream)
		vban_stream_destroy(impl->stream);
	if (impl->source)
		pw_loop_destroy_source(impl->data_loop, impl->source);

	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);

	if (impl->timer)
		pw_loop_destroy_source(impl->loop, impl->timer);

	if (impl->data_loop)
		pw_context_release_loop(impl->context, impl->data_loop);

	pw_properties_free(impl->stream_props);
	pw_properties_free(impl->props);

	free(impl->ifname);
	free(impl);
}