static inline void *spa_support_find(const struct spa_support *support,
				     uint32_t n_support,
				     const char *type)
{
	uint32_t i;
	for (i = 0; i < n_support; i++) {
		if (strcmp(support[i].type, type) == 0)
			return support[i].data;
	}
	return NULL;
}