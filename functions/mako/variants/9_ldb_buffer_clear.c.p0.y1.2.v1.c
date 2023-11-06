void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc != 0) 
    ldb_free(z->data);

  z->data = 0;
  z->size = z->alloc = 0;
}