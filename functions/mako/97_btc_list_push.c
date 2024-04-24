btc_list_push(btc_list_t *q, btc_link_t *x) {
  CHECK(x->prev == NULL);
  CHECK(x->next == NULL);

  if (q->tail == NULL) {
    q->head = x;
    q->tail = x;
    q->length = 1;
  } else {
    x->prev = q->tail;
    x->prev->next = x;
    q->tail = x;
    q->length++;
  }
}