Variant 1 - Checking for NULL pointer to lda_buffer_t struct:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL && z->alloc > 0) {
    ldb_free(z->data);
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
  }
}


Variant 2 - Using memset to Reset:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0) {
    ldb_free(z->data);
 }

 memset(z, 0, sizeof(ldb_buffer_t));
}


Variant 3 - Two stage check for clear (Free & Clear):

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL) {
    if (z->alloc > 0) {
        ldb_free(z->data);
        z->data = NULL;
    } 
    z->size = z->alloc = 0;
  }
}


Variant 4 - Additional Assertion for debugging purposes:

void ldb_buffer_clear(ldb_buffer_t *z) {
    assert(z != NULL);
    if (z->alloc > 0) {
        ldb_free(z->data);
    }
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
}


Variant 5 - Reverse Memory Free Check Condition:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (0 < z->alloc)
    ldb_free(z->data);

  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}
