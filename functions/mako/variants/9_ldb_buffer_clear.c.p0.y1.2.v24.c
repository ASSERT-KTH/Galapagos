void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z && z->alloc > 0) {
    ldb_free(z->data);
    z->data = NULL;
    z->alloc = 0;
  }
  if (z) {
    z->size = 0;
  }
}