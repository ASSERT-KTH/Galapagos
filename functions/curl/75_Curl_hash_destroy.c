Curl_hash_destroy(struct Curl_hash *h)
{
  if(h->table) {
    size_t i;
    for(i = 0; i < h->slots; ++i) {
      Curl_llist_destroy(&h->table[i], (void *) h);
    }
    Curl_safefree(h->table);
  }
  h->size = 0;
  h->slots = 0;
}