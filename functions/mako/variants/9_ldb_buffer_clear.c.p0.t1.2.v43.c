ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0) {
    z->size = 0;
    z->alloc = 0;
    ldb_free(z->data);
  } 

  else {
    z->size = 0;
  }

  z->data = NULL;
}