static int clear_buffers(struct impl *impl, struct mix *mix)
{
	uint32_t i;
	for (i = 0; i < mix->n_buffers; i++) {
		struct buffer *b = &mix->buffers[i];

		spa_log_debug(impl->log, "%p: clear buffer %d", impl, i);
		clear_buffer(impl, &b->buffer);
		pw_memblock_unref(b->mem);
	}
	mix->n_buffers = 0;
	return 0;
}