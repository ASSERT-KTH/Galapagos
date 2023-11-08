void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL) {
    if(z->alloc > 0){
       ldb_free(z->data);
    }
    /* Initialize other members*/
    z->data = NULL;
    z->size = z->alloc = 0;
  }
}