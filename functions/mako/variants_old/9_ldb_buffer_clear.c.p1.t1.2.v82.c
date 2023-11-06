Here is the new program variant:


ldb_buffer_clear(ldb_buffer_t *z) {
  assert(z != NULL);

  if (z->alloc > 0){
    if(z->data != NULL){
      ldb_free(z->data);
      z->data = NULL;
    }
    z->alloc = 0;
  }

  z->size = 0;
}
