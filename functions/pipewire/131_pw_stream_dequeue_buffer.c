struct pw_buffer *pw_stream_dequeue_buffer(struct pw_stream *stream)
{
	struct stream *impl = SPA_CONTAINER_OF(stream, struct stream, this);
	struct buffer *b;
	int res;

	if ((b = queue_pop(impl, &impl->dequeued)) == NULL) {
		res = -errno;
		pw_log_trace_fp("%p: no more buffers: %m", stream);
		errno = -res;
		return NULL;
	}
	pw_log_trace_fp("%p: dequeue buffer %d size:%"PRIu64" req:%"PRIu64,
			stream, b->id, b->this.size, b->this.requested);

	if (b->busy && impl->direction == SPA_DIRECTION_OUTPUT) {
		if (SPA_ATOMIC_INC(b->busy->count) > 1) {
			SPA_ATOMIC_DEC(b->busy->count);
			queue_push(impl, &impl->dequeued, b);
			pw_log_trace_fp("%p: buffer busy", stream);
			errno = EBUSY;
			return NULL;
		}
	}
	return &b->this;
}