ldb_buffer_clear(ldb_buffer_t *z) {
  assert(z);  // claims that the point is not null before proceeding

  if (z->alloc > 0) {
    ldb_free(z->data);
    z->data = NULL;
  }

  z->size = z->alloc = 0;
}