Variant 1:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z) {
    if (z->alloc > 0)
      ldb_free(z->data);
      
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
  }
}


Variant 2:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z == NULL)
    return;

  if (z->alloc > 0)
    ldb_free(z->data);

  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}


Variant 3:

void ldb_buffer_clear(ldb_buffer_t *z) {
  do {
    if (z->alloc > 0)
      ldb_free(z->data);
      
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
  } while (0);
}


Variant 4:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (!z)
    return;

  if (z->alloc <= 0)
    return;
    
  ldb_free(z->data);
  z->data = NULL;
  z->size = z->alloc = 0;
}
