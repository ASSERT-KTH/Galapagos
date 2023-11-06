void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc != 0){
    ldb_free(z->data);
    z->alloc = z->size = 0;
    z->data = 0;
  }
}