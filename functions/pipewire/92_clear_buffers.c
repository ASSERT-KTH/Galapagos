static void clear_buffers(struct vulkan_compute_state *s, struct vulkan_stream *p)
{
	uint32_t i;

	for (i = 0; i < p->n_buffers; i++) {
		vulkan_buffer_clear(&s->base, &p->buffers[i]);
		p->spa_buffers[i] = NULL;
	}
	p->n_buffers = 0;
	if (p->direction == SPA_DIRECTION_INPUT) {
		vulkan_staging_buffer_destroy(&s->base, &s->staging_buffer);
		s->staging_buffer.buffer = VK_NULL_HANDLE;
	}
}