void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data != NULL)
    ldb_free(z->data);
    
  z->data = NULL;
  
  if (z->size != 0)
    z->size = 0;

  if (z->alloc != 0)  
    z->alloc = 0;
}