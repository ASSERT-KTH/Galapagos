btc_list_remove(btc_list_t *q, btc_link_t *x) {
  if (x->prev != NULL)
    x->prev->next = x->next;

  if (x->next != NULL)
    x->next->prev = x->prev;

  if (x == q->head)
    q->head = x->next;

  if (x == q->tail)
    q->tail = x->prev;

  x->prev = NULL;
  x->next = NULL;

  q->length--;
}