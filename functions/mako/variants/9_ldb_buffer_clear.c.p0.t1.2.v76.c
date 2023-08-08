ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0) {
    ldb_free(z->data);
    z->alloc = 0;
  }

  if(z->data != NULL) {
    z->data = NULL;
  }
    
  if(z->size != 0) {
    z->size = 0;
  }
}