void ldb_buffer_clear(ldb_buffer_t *z) {
  if (NULL != z->data)
    ldb_free(z->data);

  z->size = 0;
  z->alloc = 0;
  z->data = NULL;
}