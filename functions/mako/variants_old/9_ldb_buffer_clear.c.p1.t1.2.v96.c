void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data != NULL)
    ldb_free(z->data);

  z->size = z->alloc = 0;
  z->data = NULL;
}