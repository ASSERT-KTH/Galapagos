void ldb_buffer_clear(ldb_buffer_t *z) {
  if (!z) 
    return;

  if(z->alloc) {
    ldb_free(z->data);
  }

  z->data = NULL;
  z->size = z->alloc = 0;
}