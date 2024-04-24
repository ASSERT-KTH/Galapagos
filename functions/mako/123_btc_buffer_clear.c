btc_buffer_clear(btc_buffer_t *z) {
  if (z->alloc > 0)
    btc_free(z->data);

  z->data = NULL;
  z->alloc = 0;
  z->length = 0;
}