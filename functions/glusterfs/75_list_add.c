list_add (struct list_head *new, struct list_head *head)
{
	new->prev = head;
	new->next = head->next;

	new->prev->next = new;
	new->next->prev = new;
}