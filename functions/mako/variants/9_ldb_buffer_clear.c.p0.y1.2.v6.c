void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc) {
    ldb_free(z->data);

    z->data = 0;
    z->size = z->alloc = 0;
  }
}