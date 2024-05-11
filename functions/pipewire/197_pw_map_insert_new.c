static inline uint32_t pw_map_insert_new(struct pw_map *map, void *data)
{
	union pw_map_item *start, *item;
	uint32_t id;

	if (map->free_list != SPA_ID_INVALID) {
		start = (union pw_map_item *) map->items.data;
		item = &start[map->free_list >> 1]; /* lsb always 1, see pw_map_remove */
		map->free_list = item->next;
	} else {
		item = (union pw_map_item *) pw_array_add(&map->items, sizeof(union pw_map_item));
		if (item == NULL)
			return SPA_ID_INVALID;
		start = (union pw_map_item *) map->items.data;
	}
	item->data = data;
	id = (item - start);
	return id;
}