static void impl_destroy(struct impl *impl)
{
	struct session *sess;

	spa_list_consume(sess, &impl->sessions, link)
		free_session(sess);

	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);

	if (impl->timer)
		pw_loop_destroy_source(impl->loop, impl->timer);
	if (impl->ctrl_source)
		pw_loop_destroy_source(impl->loop, impl->ctrl_source);
	if (impl->data_source)
		pw_loop_destroy_source(impl->data_loop, impl->data_source);

	if (impl->client)
		avahi_client_free(impl->client);

	if (impl->data_loop)
		pw_context_release_loop(impl->context, impl->data_loop);

	pw_properties_free(impl->stream_props);
	pw_properties_free(impl->props);

	free(impl->ifname);
	free(impl->ts_refclk);
	free(impl->session_name);
	free(impl);
}