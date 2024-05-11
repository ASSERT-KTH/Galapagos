static void impl_destroy(struct impl *impl)
{
	if (impl->stream)
		pw_stream_destroy(impl->stream);
	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);

	if (impl->filename) {
		if (impl->unlink_fifo)
			unlink(impl->filename);
		free(impl->filename);
	}
	if (impl->socket)
		pw_loop_destroy_source(impl->data_loop, impl->socket);
	if (impl->timer)
		pw_loop_destroy_source(impl->data_loop, impl->timer);
	if (impl->fd >= 0)
		close(impl->fd);

	pw_context_release_loop(impl->context, impl->data_loop);

	pw_properties_free(impl->stream_props);
	pw_properties_free(impl->props);

	free(impl->buffer);
	free(impl);
}