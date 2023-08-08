ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0){
    ldb_free(z->data);
    z->alloc = 0;
  }

  z->data = NULL;
  z->size = 0;
}