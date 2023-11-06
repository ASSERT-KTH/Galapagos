ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data != NULL) {
    ldb_free(z->data);
    z->data = NULL;
  }
  if (z->alloc > 0)
    z->alloc = 0;  
  if (z->size != 0)
    z->size = 0;
}