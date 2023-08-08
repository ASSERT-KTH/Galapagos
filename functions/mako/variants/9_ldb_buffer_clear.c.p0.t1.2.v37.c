ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data != NULL)
    ldb_free(z->data);

  memset(z, 0, sizeof(*z));
}