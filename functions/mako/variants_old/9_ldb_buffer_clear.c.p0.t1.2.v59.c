ldb_buffer_clear(ldb_buffer_t *z) {
  if (!z) return;

  if (z->alloc > 0 && z->data != NULL) {
    ldb_free(z->data);
  }

  z->data = NULL;
  z->alloc = 0;
  z->size = 0;
}