struct tplg_elem *tplg_elem_lookup(struct list_head *base, const char* id,
				   unsigned int type, int index)
{
	struct list_head *pos;
	struct tplg_elem *elem;

	if (!base || !id)
		return NULL;

	list_for_each(pos, base) {

		elem = list_entry(pos, struct tplg_elem, list);

		if (!strcmp(elem->id, id) && elem->type == type)
			return elem;
		/* SND_TPLG_INDEX_ALL is the default value "0" and applicable
		   for all use cases */
		if ((index != SND_TPLG_INDEX_ALL)
			&& (elem->index > index))
			break;
	}

	return NULL;
}