void pw_stream_add_listener(struct pw_stream *stream,
			    struct spa_hook *listener,
			    const struct pw_stream_events *events,
			    void *data)
{
	struct stream *impl = SPA_CONTAINER_OF(stream, struct stream, this);

	ensure_loop(impl->main_loop);

	spa_hook_list_append(&stream->listener_list, listener, events, data);

	if (events->process && impl->rt_callbacks.funcs == NULL) {
		impl->rt_callbacks = SPA_CALLBACKS_INIT(events, data);
		listener->removed = hook_removed;
		listener->priv = impl;
	}
}