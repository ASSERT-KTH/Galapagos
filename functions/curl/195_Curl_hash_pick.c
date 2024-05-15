Curl_hash_pick(struct Curl_hash *h, void *key, size_t key_len)
{
  struct Curl_llist_element *le;
  struct Curl_llist *l;

  DEBUGASSERT(h);
  if(h->table) {
    DEBUGASSERT(h->slots);
    l = FETCH_LIST(h, key, key_len);
    for(le = l->head; le; le = le->next) {
      struct Curl_hash_element *he = le->ptr;
      if(h->comp_func(he->key, he->key_len, key, key_len)) {
        return he->ptr;
      }
    }
  }

  return NULL;
}