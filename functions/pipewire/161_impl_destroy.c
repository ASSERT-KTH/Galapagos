static void impl_destroy(struct impl *impl)
{
	if (impl->client) {
		jack.deactivate(impl->client);
		jack.client_close(impl->client);
	}
	if (impl->source.filter)
		pw_filter_destroy(impl->source.filter);
	if (impl->sink.filter)
		pw_filter_destroy(impl->sink.filter);
	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);

	pw_properties_free(impl->sink.props);
	pw_properties_free(impl->source.props);
	pw_properties_free(impl->props);

	free(impl);
}