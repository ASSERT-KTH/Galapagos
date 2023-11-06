ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data != NULL) 
    ldb_free(z->data);

  z->data = NULL;
  z->size = 0;
  z->alloc = 0;

  // Log the occurrence of a buffer clear operation (can be useful for debugging)
  //printf("Buffer cleared\n");
}