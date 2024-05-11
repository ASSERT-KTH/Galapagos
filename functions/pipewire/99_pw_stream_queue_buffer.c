int pw_stream_queue_buffer(struct pw_stream *stream, struct pw_buffer *buffer)
{
	struct stream *impl = SPA_CONTAINER_OF(stream, struct stream, this);
	struct buffer *b = SPA_CONTAINER_OF(buffer, struct buffer, this);
	int res;

	if (b->busy)
		SPA_ATOMIC_DEC(b->busy->count);

	pw_log_trace_fp("%p: queue buffer %d size:%"PRIu64, stream, b->id,
			b->this.size);
	if ((res = queue_push(impl, &impl->queued, b)) < 0)
		return res;

	if (impl->direction == SPA_DIRECTION_OUTPUT &&
	    stream->node->driving && !impl->using_trigger) {
		pw_log_debug("deprecated: use pw_stream_trigger_process() to drive the stream.");
		res = pw_loop_invoke(impl->data_loop,
			do_trigger_deprecated, 1, NULL, 0, false, impl);
	}
	return res;
}