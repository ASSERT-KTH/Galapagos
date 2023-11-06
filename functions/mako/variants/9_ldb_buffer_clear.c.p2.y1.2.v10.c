void ldb_buffer_clear(ldb_buffer_t *z) {
  if(NULL != z->data && z->alloc > 0) {
    ldb_free(z->data);
    z->data = NULL;
  }
  z->size = z->alloc = 0;
}