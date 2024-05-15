void _libssh2_list_add(struct list_head *head,
                       struct list_node *entry)
{
    /* store a pointer to the head */
    entry->head = head;

    /* we add this entry at the "top" so it has no next */
    entry->next = NULL;

    /* make our prev point to what the head thinks is last */
    entry->prev = head->last;

    /* and make head's last be us now */
    head->last = entry;

    /* make sure our 'prev' node points to us next */
    if(entry->prev)
        entry->prev->next = entry;
    else
        head->first = entry;
}