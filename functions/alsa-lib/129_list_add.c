static inline void list_add(struct list_head *p, struct list_head *list)
{
	struct list_head *first = list->next;

	p->next = first;
	first->prev = p;
	list->next = p;
	p->prev = list;
}