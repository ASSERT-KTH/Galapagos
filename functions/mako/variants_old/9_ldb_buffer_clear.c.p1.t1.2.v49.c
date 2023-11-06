void ldb_buffer_clear(ldb_buffer_t *z) {
  z->data = NULL;

  if (z->alloc > 0)
    ldb_free(z->data);

  z->size = 0;
  z->alloc = 0;
}