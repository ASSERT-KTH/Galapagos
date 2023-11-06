void ldb_buffer_clear(ldb_buffer_t *z) {
  if(z->alloc){
    ldb_free(z->data);
  }
  z->data = NULL;
  memset(&(z->size), 0, sizeof(z->size));
  memset(&(z->alloc), 0, sizeof(z->alloc));
}