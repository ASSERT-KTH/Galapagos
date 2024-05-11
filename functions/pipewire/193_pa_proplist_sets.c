static inline int pa_proplist_sets(pa_proplist *p, const char *key, const char *value)
{
	pa_proplist_item *item = pa_proplist_item_find(p, key);
	if (item != NULL)
		pa_proplist_item_free(item);
        else
                item = pa_array_add(&p->array, sizeof(*item));
	item->key = strdup(key);
	item->value = strdup(value);
	return 0;
}