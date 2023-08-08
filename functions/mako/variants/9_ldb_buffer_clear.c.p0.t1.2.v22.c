ldb_buffer_clear(ldb_buffer_t *z) {
  assert(z != NULL);

  if (z->alloc > 0) {
    memset(z->data, 0, z->alloc);
    ldb_free(z->data);
  }
  
  memset(z, 0, sizeof(ldb_buffer_t));
}