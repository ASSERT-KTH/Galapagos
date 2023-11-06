
void ldb_buffer_clear_var1(ldb_buffer_t *z) {
  if (z != NULL && z->alloc > 0) {
    ldb_free(z->data);
  }

  if (z != NULL) {
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
  }
}



void ldb_buffer_clear_var2(ldb_buffer_t *z) {
  assert(z != NULL);
  if (z->alloc > 0) {
    ldb_free(z->data);
  }

  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}



void ldb_buffer_clear_var3(ldb_buffer_t *z) {
  if ((z != NULL) && (z->alloc > 0)) {
    ldb_free(z->data);
    z->data = NULL;
  }

  if (z != NULL) {
    z->size = z->alloc = 0;
  }
}



void ldb_buffer_clear_var4(ldb_buffer_t *z) {
  if (z == NULL)
    return;

  if (z->alloc > 0) {
    ldb_free(z->data);
  }

  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}