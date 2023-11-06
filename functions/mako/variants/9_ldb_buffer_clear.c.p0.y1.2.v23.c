void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z -> alloc != 0) {
    ldb_free(z -> data);
    z -> alloc = z -> alloc - z -> alloc;
  }
  z -> size = z -> alloc;
  z -> data = NULL;
}