static void impl_destroy(struct impl *impl)
{
	/* deactivate both streams before destroying any of them */
	if (impl->capture)
		pw_stream_set_active(impl->capture, false);
	if (impl->playback)
		pw_stream_set_active(impl->playback, false);

	if (impl->capture)
		pw_stream_destroy(impl->capture);
	if (impl->playback)
		pw_stream_destroy(impl->playback);

	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);

	pw_properties_free(impl->capture_props);
	pw_properties_free(impl->playback_props);
	free(impl);
}