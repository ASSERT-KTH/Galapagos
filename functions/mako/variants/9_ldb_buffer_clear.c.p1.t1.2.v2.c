void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc) {
    z->alloc = 0;
    ldb_free(z->data);
  }

  z->data = NULL;
  z->size = 0;
}