void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z == NULL)
    return;
    
  free(z->data);
  z->data = NULL;
  z->size = z->alloc = 0;
}