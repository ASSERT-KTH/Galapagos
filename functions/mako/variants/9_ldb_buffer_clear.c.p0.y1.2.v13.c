void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data != NULL) {
    ldb_free(z->data);
    z->data = NULL;
  }
    
  z->size = z->alloc = 0;
}