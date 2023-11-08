void ldb_buffer_clear(ldb_buffer_t *z) {
  z->size = 0;
  z->alloc = 0;

  if (z->data != NULL) {
    ldb_free(z->data);
    z->data = NULL;
  }
}