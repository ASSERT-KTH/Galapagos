void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z == NULL)
    return;

  z->data = NULL;
  if (z->alloc)  
    ldb_free(z->data);
  
  z->size = z->alloc = 0;
}