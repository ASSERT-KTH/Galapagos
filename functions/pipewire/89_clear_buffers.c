static void clear_buffers(struct vulkan_blit_state *s, struct vulkan_stream *p)
{
	uint32_t i;

	for (i = 0; i < p->n_buffers; i++) {
		vulkan_buffer_clear(&s->base, &p->buffers[i]);
		p->spa_buffers[i] = NULL;
	}
	p->n_buffers = 0;
	p->buffer_type = SPA_DATA_Invalid;
	p->maxsize = 0;
}