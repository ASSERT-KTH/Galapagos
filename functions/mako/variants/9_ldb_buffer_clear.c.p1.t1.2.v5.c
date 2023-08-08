void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL) {
    if (z->alloc > 0) {
      ldb_free(z->data);
    }

    z->data = NULL;
    z->alloc = 0;
  }
  z->size = 0;
}