Curl_hash_init(struct Curl_hash *h,
               size_t slots,
               hash_function hfunc,
               comp_function comparator,
               Curl_hash_dtor dtor)
{
  DEBUGASSERT(h);
  DEBUGASSERT(slots);
  DEBUGASSERT(hfunc);
  DEBUGASSERT(comparator);
  DEBUGASSERT(dtor);

  h->table = NULL;
  h->hash_func = hfunc;
  h->comp_func = comparator;
  h->dtor = dtor;
  h->size = 0;
  h->slots = slots;
}