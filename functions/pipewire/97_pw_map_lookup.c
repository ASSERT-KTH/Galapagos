static inline void *pw_map_lookup(const struct pw_map *map, uint32_t id)
{
	if (SPA_LIKELY(pw_map_check_id(map, id))) {
		union pw_map_item *item = pw_map_get_item(map, id);
		if (!pw_map_item_is_free(item))
			return item->data;
	}
	return NULL;
}