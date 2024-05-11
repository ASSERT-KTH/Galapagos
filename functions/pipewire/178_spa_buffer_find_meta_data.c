static inline void *spa_buffer_find_meta_data(const struct spa_buffer *b, uint32_t type, size_t size)
{
	struct spa_meta *m;
	if ((m = spa_buffer_find_meta(b, type)) && m->size >= size)
		return m->data;
	return NULL;
}