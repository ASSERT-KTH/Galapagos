static void impl_destroy(struct impl *impl)
{
	uint32_t i;
	if (impl->capture)
		pw_stream_destroy(impl->capture);
	if (impl->source)
		pw_stream_destroy(impl->source);
	if (impl->playback)
		pw_stream_destroy(impl->playback);
	if (impl->sink)
		pw_stream_destroy(impl->sink);
	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);
	if (impl->spa_handle)
		spa_plugin_loader_unload(impl->loader, impl->spa_handle);
	pw_properties_free(impl->capture_props);
	pw_properties_free(impl->source_props);
	pw_properties_free(impl->playback_props);
	pw_properties_free(impl->sink_props);

	for (i = 0; i < impl->rec_info.channels; i++)
		free(impl->rec_buffer[i]);
	for (i = 0; i < impl->play_info.channels; i++)
		free(impl->play_buffer[i]);
	for (i = 0; i < impl->out_info.channels; i++)
		free(impl->out_buffer[i]);

	free(impl);
}