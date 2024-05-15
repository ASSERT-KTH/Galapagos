void Curl_hash_start_iterate(struct Curl_hash *hash,
                             struct Curl_hash_iterator *iter)
{
  iter->hash = hash;
  iter->slot_index = 0;
  iter->current_element = NULL;
}