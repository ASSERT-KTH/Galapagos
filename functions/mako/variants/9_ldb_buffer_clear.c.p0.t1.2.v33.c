ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL && z->alloc > 0) 
    ldb_free(z->data);

  if (z != NULL){
    z->data = NULL; 
    z->size = 0; 
    z->alloc = 0;
  }
}