btc_buffer_set(btc_buffer_t *z, const uint8_t *xp, size_t xn) {
  btc_buffer_grow(z, xn);

  if (xn > 0)
    memcpy(z->data, xp, xn);

  z->length = xn;
}