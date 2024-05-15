list_add_tail (struct list_head *new, struct list_head *head)
{
	new->next = head;
	new->prev = head->prev;

	new->prev->next = new;
	new->next->prev = new;
}