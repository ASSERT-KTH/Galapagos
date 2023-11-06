
void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z == NULL)
    return;

  if (z->alloc > 0) {
    ldb_free(z->data);
    z->data = NULL;
  }  

  z->size = 0;
  z->alloc = 0;
}



void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL && z->alloc > 0)
    ldb_free(z->data);
    
  if (z != NULL) {
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
  }
}
 


void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc <= 0)
    return;
    
  ldb_free(z->data);
  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}
=  
