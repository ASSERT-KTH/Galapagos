static int clear_buffers(struct client *c, struct mix *mix)
{
	struct port *port = mix->port;
	struct buffer *b;
	uint32_t i, j;

	pw_log_debug("%p: port %p clear buffers", c, port);

	for (i = 0; i < mix->n_buffers; i++) {
		b = &mix->buffers[i];

		for (j = 0; j < b->n_mem; j++)
			pw_memmap_free(b->mem[j]);

		b->n_mem = 0;
	}
	mix->n_buffers = 0;
	spa_list_init(&mix->queue);
	return 0;
}