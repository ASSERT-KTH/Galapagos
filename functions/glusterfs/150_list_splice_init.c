list_splice_init (struct list_head *list, struct list_head *head)
{
	if (list_empty (list))
		return;

	__list_splice (list, head);
	INIT_LIST_HEAD (list);
}