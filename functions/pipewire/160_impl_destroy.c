static void impl_destroy(struct impl *impl)
{
	struct plugin_func *pl;

	/* disconnect both streams before destroying any of them */
	if (impl->capture)
		pw_stream_disconnect(impl->capture);
	if (impl->playback)
		pw_stream_disconnect(impl->playback);

	if (impl->capture)
		pw_stream_destroy(impl->capture);
	if (impl->playback)
		pw_stream_destroy(impl->playback);

	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);

	pw_properties_free(impl->capture_props);
	pw_properties_free(impl->playback_props);
	graph_free(&impl->graph);
	spa_list_consume(pl, &impl->plugin_func_list, link)
		free_plugin_func(pl);

	free(impl->silence_data);
	free(impl->discard_data);
	free(impl);
}