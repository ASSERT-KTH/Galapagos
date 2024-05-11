static void impl_destroy(struct impl *impl)
{
	struct session *sess;

	spa_list_consume(sess, &impl->sessions, link)
		session_free(sess);

	if (impl->registry) {
		spa_hook_remove(&impl->registry_listener);
		pw_proxy_destroy((struct pw_proxy*)impl->registry);
		impl->registry = NULL;
	}
	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);

	if (impl->timer)
		pw_loop_destroy_source(impl->loop, impl->timer);
	if (impl->sap_source)
		pw_loop_destroy_source(impl->loop, impl->sap_source);

	if (impl->sap_fd != -1)
		close(impl->sap_fd);
	if (impl->ptp_fd != -1)
		close(impl->ptp_fd);

	pw_properties_free(impl->props);

	free(impl->extra_attrs_preamble);
	free(impl->extra_attrs_end);

	free(impl->ptp_mgmt_socket);
	free(impl->ifname);
	free(impl);
}