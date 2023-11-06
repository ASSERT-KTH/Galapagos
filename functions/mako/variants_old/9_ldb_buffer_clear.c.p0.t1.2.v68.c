ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc != 0)
     ldb_FREE(z->data);

  memset(z, 0, sizeof(ldb_buffer_t));
}