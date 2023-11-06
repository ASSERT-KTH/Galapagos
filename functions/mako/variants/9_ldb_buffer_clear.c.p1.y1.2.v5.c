1.

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL && z->alloc > 0)
    ldb_free(z->data);

  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}

2.

void ldb_buffer_clear(ldb_buffer_t *z) {
  assert(z != NULL);

  if (z->alloc > 0)
    ldb_free(z->data);

  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}

3.

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z == NULL)
    return;

  if (z->alloc > 0)
    ldb_free(z->data);

  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}

4.

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z && z->alloc)
    ldb_free(z->data);

  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}
