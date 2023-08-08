void ldb_buffer_clear(ldb_buffer_t *z) {
  if (!z)
    return;

  if (z->alloc > 0 && z->data) {
    ldb_free(z->data);
  }

  memset (z, 0, sizeof (ldb_buffer_t));
}