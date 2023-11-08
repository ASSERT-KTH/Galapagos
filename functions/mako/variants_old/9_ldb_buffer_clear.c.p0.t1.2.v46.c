ldb_buffer_clear(ldb_buffer_t *z) {
  assert(z != NULL);

  if (z->data != NULL)
    ldb_free(z->data);

  memset(z, 0, sizeof(ldb_buffer_t));
}