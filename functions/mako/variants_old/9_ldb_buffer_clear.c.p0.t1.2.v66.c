ldb_buffer_clear(ldb_buffer_t *z) { 
  if (z == NULL) 
    return; 
  if (z->data != NULL) {
    ldb_free(z->data); 
    z->data = NULL; 
  }
  z->size = 0; 
  z->alloc = 0; 
}