Variant 1:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data) {
    ldb_free(z->data);
  }
 
  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}


Variant 2:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (!(z->alloc == 0))
    ldb_free(z->data);

  z->data = NULL;
  z->size = z->alloc = 0;
}


Variant 3:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data != NULL) 
    ldb_free(z->data);

  memset(z, 0, sizeof(ldb_buffer_t));
}


Variant 4:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data != NULL) {
      ldb_free(z->data);
      z->data = NULL; 
  }
  if (z->size != 0)
      z->size = 0;
  if (z->alloc != 0)
      z->alloc = 0;  
}
