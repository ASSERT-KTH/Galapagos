ldb_buffer_clear(ldb_buffer_t *z) {
  assert(z != NULL); // checking if z is valid

  if (z->alloc >= 0)
  {
    ldb_free(z->data);
    
    z->data = NULL;
    z->size = z->alloc = 0;
  }
}