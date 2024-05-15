Curl_hash_next_element(struct Curl_hash_iterator *iter)
{
  struct Curl_hash *h = iter->hash;

  if(!h->table)
    return NULL; /* empty hash, nothing to return */

  /* Get the next element in the current list, if any */
  if(iter->current_element)
    iter->current_element = iter->current_element->next;

  /* If we have reached the end of the list, find the next one */
  if(!iter->current_element) {
    size_t i;
    for(i = iter->slot_index; i < h->slots; i++) {
      if(h->table[i].head) {
        iter->current_element = h->table[i].head;
        iter->slot_index = i + 1;
        break;
      }
    }
  }

  if(iter->current_element) {
    struct Curl_hash_element *he = iter->current_element->ptr;
    return he;
  }
  return NULL;
}