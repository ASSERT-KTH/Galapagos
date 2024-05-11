static int clear_buffers(struct node_data *data, struct mix *mix)
{
	struct pw_impl_port *port = mix->port;
        struct buffer *b;
	int res;

        pw_log_debug("port %p: clear %zd buffers mix:%d", port,
			pw_array_get_len(&mix->buffers, struct buffer),
			mix->mix.id);

	if ((res = pw_impl_port_use_buffers(port, &mix->mix, 0, NULL, 0)) < 0) {
		pw_log_error("port %p: error clear buffers %s", port, spa_strerror(res));
		return res;
	}

        pw_array_for_each(b, &mix->buffers) {
		pw_log_debug("port %p: clear buffer %d map %p %p",
			port, b->id, b->mem, b->buf);
		pw_memmap_free(b->mem);
		free(b->buf);
        }
	mix->buffers.size = 0;
	return 0;
}