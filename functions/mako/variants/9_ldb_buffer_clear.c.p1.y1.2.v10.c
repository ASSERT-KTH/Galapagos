Version 1:
Way to check if z->data is allocated before trying to free it.

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL && z->data) {
    ldb_free(z->data);
    z->data = NULL;
  }

  if (z != NULL) {
    z->size = 0;
    z->alloc = 0;
  }
}


Version 2:
Flipping the conditions and performing NULL assignment regardless of the condition

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (NULL == z) {
    return;
  }

  if (0 < z->alloc) {
    ldb_free(z->data);
  }

  z->data = NULL;
  z->size = z->alloc = 0;
}


Version 3:
Placing conditions within the statements

void ldb_buffer_clear(ldb_buffer_t *z) {
  z && z->data ? ldb_free(z->data), z->data = NULL : 0;
  if (z) {
    z->size = 0;
    z->alloc = 0;
  }
}
