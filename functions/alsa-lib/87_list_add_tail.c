static inline void list_add_tail(struct list_head *p, struct list_head *list)
{
	struct list_head *last = list->prev;

	last->next = p;
	p->prev = last;
	p->next = list;
	list->prev = p;
}