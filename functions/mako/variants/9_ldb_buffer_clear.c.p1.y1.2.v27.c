Variant 1:

ldb_buffer_clear(ldb_buffer_t *z) {  
  if (z != NULL) {  
    if (z->data != NULL){
      ldb_free(z->data);
      z->data = NULL;
      z->alloc = z->size = 0;
    }
  }
}

Variant 2:

ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0) {
    ldb_free(z->data);
  }
  
  memset(z, 0, sizeof(ldb_buffer_t));
}
