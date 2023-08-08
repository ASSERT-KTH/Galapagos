void ldb_buffer_clear(ldb_buffer_t *z) {
  z->data = z->alloc > 0 ? ldb_free(z->data), NULL : NULL;
  z->size = 0;
  z->alloc = 0;
}