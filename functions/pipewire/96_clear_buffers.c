static void clear_buffers(struct port *port)
{
	uint32_t i, j;
	struct filter *impl = port->filter;

	pw_log_debug("%p: clear buffers %d", impl, port->n_buffers);

	for (i = 0; i < port->n_buffers; i++) {
		struct buffer *b = &port->buffers[i];

		if (SPA_FLAG_IS_SET(b->flags, BUFFER_FLAG_ADDED))
			pw_filter_emit_remove_buffer(&impl->this, port->user_data, &b->this);

		if (SPA_FLAG_IS_SET(b->flags, BUFFER_FLAG_MAPPED)) {
			for (j = 0; j < b->this.buffer->n_datas; j++) {
				struct spa_data *d = &b->this.buffer->datas[j];
				if (SPA_FLAG_IS_SET(d->flags, SPA_DATA_FLAG_MAPPABLE)) {
					pw_log_debug("%p: clear buffer %d mem",
							impl, b->id);
					unmap_data(impl, d);
				}
			}
		}
	}
	port->n_buffers = 0;
	clear_queue(port, &port->dequeued);
	clear_queue(port, &port->queued);
}