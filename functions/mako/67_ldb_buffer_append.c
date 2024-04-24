ldb_buffer_append(ldb_buffer_t *z, const uint8_t *xp, size_t xn) {
  uint8_t *zp = ldb_buffer_expand(z, xn);

  if (xn > 0)
    memcpy(zp, xp, xn);

  z->size += xn;
}