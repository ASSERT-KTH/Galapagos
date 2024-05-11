static void impl_destroy(struct impl *impl)
{
	if (impl->stream)
		rtp_stream_destroy(impl->stream);
	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);

	if (impl->rtsp)
		pw_rtsp_client_destroy(impl->rtsp);

	if (impl->ctx)
		EVP_CIPHER_CTX_free(impl->ctx);

	pw_properties_free(impl->headers);
	pw_properties_free(impl->stream_props);
	pw_properties_free(impl->props);
	free(impl->password);
	free(impl);
}