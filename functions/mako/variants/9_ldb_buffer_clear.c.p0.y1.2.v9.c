void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc) {
    ldb_free(z->data);
  }

  z->alloc = z->size = 0;
  z->data = NULL;
}