
void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL && z->alloc > 0)
    ldb_free(z->data);

  if (z != NULL) {
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
  }
}


or 


void ldb_buffer_clear(ldb_buffer_t *z) {
  z->alloc = 0;

  if (z->data != NULL) {
    ldb_free(z->data);
	z->data = NULL;
  }

  z->size = 0;
}
 

or 


void ldb_buffer_clear(ldb_buffer_t *z) {

   if (z == NULL)
      return; 

   if (z->alloc > 0)
     ldb_free(z->data);

   z->data = NULL;
   z->size = 0;
   z->alloc = 0;
}
 

or


void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z == NULL)
    return;

  if (z->data) {
    ldb_free(z->data);
    z->data = NULL;
  }
  
  z->size = z->alloc = 0;
}
