list_del (struct list_head *old)
{
	old->prev->next = old->next;
	old->next->prev = old->prev;

	old->next = (void *)0xbabebabe;
	old->prev = (void *)0xcafecafe;
}