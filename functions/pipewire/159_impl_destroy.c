static void impl_destroy(struct impl *impl)
{
	uint32_t i;

	if (impl->reset_work_id != SPA_ID_INVALID)
		pw_work_queue_cancel(pw_context_get_work_queue(impl->context),
				     impl, SPA_ID_INVALID);

	close_ffado_device(impl);

	destroy_stream(&impl->source);
	destroy_stream(&impl->sink);

	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);
	if (impl->ffado_timer)
		pw_loop_destroy_source(impl->data_loop, impl->ffado_timer);

	if (impl->data_loop)
		pw_context_release_loop(impl->context, impl->data_loop);

	pw_properties_free(impl->sink.props);
	pw_properties_free(impl->source.props);
	pw_properties_free(impl->props);

	for (i = 0; i < impl->n_devices; i++)
		free(impl->devices[i]);
	free(impl);
}