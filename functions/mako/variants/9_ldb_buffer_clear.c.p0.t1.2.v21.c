ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data != NULL) {
    ldb_free(z->data);
    z->data = NULL;
  }

  //<Assuming simple data type or =/- operators>
  if (z->size != 0) {
      z->size-= z->size;
  }

  if(z->alloc>0){
     z->alloc = z->alloc-z->alloc;
  }
}