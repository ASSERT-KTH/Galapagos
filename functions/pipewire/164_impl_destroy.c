static void impl_destroy(struct impl *impl)
{
	struct follower *f;

	if (impl->setup_socket) {
		pw_loop_destroy_source(impl->main_loop, impl->setup_socket);
		impl->setup_socket = NULL;
	}
	spa_list_consume(f, &impl->follower_list, link)
		follower_free(f);

	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);

	if (impl->data_loop)
		pw_context_release_loop(impl->context, impl->data_loop);

	pw_properties_free(impl->sink_props);
	pw_properties_free(impl->source_props);
	pw_properties_free(impl->props);

	free(impl);
}