void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z == NULL)
    return;

  if (z->alloc > 0)
    // Free the data
    ldb_free(z->data);
  
  // Initialize attributes
  z->data = NULL;
  z->size = z->alloc = 0;
}