int pw_stream_update_params(struct pw_stream *stream,
			const struct spa_pod **params,
			uint32_t n_params)
{
	struct stream *impl = SPA_CONTAINER_OF(stream, struct stream, this);
	int res;

	ensure_loop(impl->main_loop, return -EIO);

	pw_log_debug("%p: update params", stream);
	if ((res = update_params(impl, SPA_ID_INVALID, params, n_params)) < 0)
		return res;

	if (impl->in_emit_param_changed == 0) {
		emit_node_info(impl, false);
		emit_port_info(impl, false);
	}
	return res;
}