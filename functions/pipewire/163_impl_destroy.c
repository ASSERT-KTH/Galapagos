static void impl_destroy(struct impl *impl)
{
	destroy_netjack2_socket(impl);

	if (impl->source.filter)
		pw_filter_destroy(impl->source.filter);
	if (impl->sink.filter)
		pw_filter_destroy(impl->sink.filter);
	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);

	if (impl->timer)
		pw_loop_destroy_source(impl->main_loop, impl->timer);

	if (impl->data_loop)
		pw_context_release_loop(impl->context, impl->data_loop);

	pw_properties_free(impl->sink.props);
	pw_properties_free(impl->source.props);
	pw_properties_free(impl->props);

	free(impl);
}