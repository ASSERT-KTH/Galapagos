btc_zinv_clear(btc_zinv_t *z) {
  if (z->alloc > 0)
    btc_free(z->items);

  z->items = NULL;
  z->alloc = 0;
  z->length = 0;
}