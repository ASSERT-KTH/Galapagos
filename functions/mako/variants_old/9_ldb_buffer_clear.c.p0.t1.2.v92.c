ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0)
    ldb_free(z->data);

  z->data = NULL;
  memset(z, 0, sizeof(ldb_buffer_t));
}