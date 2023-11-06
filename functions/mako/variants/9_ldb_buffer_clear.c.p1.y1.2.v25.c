Variant 1:

ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data != NULL) {
    ldb_free(z->data);
  }
  
  z->data = NULL;
  z->size = z->alloc = 0;
}


Variant 2:

ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0) {
    ldb_free(z->data);
    z->alloc = z->size = 0;
  }

  z->data = NULL;
}


Variant 3:

ldb_buffer_clear(ldb_buffer_t *z)
{
    if (z->alloc <=0) return;
    
    ldb_with_free_func_t dest = (ldb_with_free_func_t *) z;
    if(dest->free_func)
		                        dest->free_func( dest->str, dest->len );
    
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
}


Variant 4:

ldb_buffer_clear(ldb_buffer_t *z) {
  if (!z->alloc) {
    return;
  }
  
  ldb_free(z->data);
  z->data = NULL;
  z->size = z->alloc = 0;
}
