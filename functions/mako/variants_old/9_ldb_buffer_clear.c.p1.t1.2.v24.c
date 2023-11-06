void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data != NULL) {
    // If the `alloc` attribute is more than 0, this statement also works
    ldb_free(z->data);

    z->data = NULL;
  }
  z->size = 0;
  z->alloc = 0;
}