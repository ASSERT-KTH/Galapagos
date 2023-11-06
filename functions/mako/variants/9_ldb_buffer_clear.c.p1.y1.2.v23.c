Variant 1:

ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0) {
    ldb_free(z->data);
    z->alloc = 0;
  }

  z->data = NULL;
  z->size = 0;
}


Variant 2:

ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0) {
    ldb_free(z->data);
    z->data = NULL;
  }

  z->size = 0;
  z->alloc = 0;
}


Variant 3:

ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0) {
    ldb_free(z->data);
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
  }
}


Variant 4:

ldb_buffer_clear(ldb_buffer_t *z) {

  if (z->alloc > 0)
    ldb_free(z->data),
    z->alloc = 0;

  z->data = NULL;
  z->size = 0;
}
