void tplg_elem_free_list(struct list_head *base)
{
	struct list_head *pos, *npos;
	struct tplg_elem *elem;

	list_for_each_safe(pos, npos, base) {
		elem = list_entry(pos, struct tplg_elem, list);
		tplg_elem_free(elem);
	}
}