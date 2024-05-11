static void impl_destroy(struct impl *impl)
{
	if (impl->stream)
		rtp_stream_destroy(impl->stream);

	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);

	if (impl->rtp_fd != -1)
		close(impl->rtp_fd);

	pw_properties_free(impl->stream_props);
	pw_properties_free(impl->props);

	free(impl->ifname);
	free(impl->session_name);
	free(impl);
}