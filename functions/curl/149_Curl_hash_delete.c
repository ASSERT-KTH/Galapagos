int Curl_hash_delete(struct Curl_hash *h, void *key, size_t key_len)
{
  struct Curl_llist_element *le;
  struct Curl_llist *l;

  DEBUGASSERT(h);
  DEBUGASSERT(h->slots);
  if(h->table) {
    l = FETCH_LIST(h, key, key_len);

    for(le = l->head; le; le = le->next) {
      struct Curl_hash_element *he = le->ptr;
      if(h->comp_func(he->key, he->key_len, key, key_len)) {
        Curl_llist_remove(l, le, (void *) h);
        --h->size;
        return 0;
      }
    }
  }
  return 1;
}