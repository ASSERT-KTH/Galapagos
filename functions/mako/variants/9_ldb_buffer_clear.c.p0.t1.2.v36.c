ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->data != NULL) 
    ldb_free(z->data);

  memset(&z->data, 0, sizeof(z->data));
  memset(&z->size, 0, sizeof(z->size));
  memset(&z->alloc, 0, sizeof(z->alloc));
}
