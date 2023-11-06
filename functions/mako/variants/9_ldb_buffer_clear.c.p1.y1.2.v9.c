Variant 1:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0 && z->data){
    ldb_free(z->data);
  }

  z->data = NULL;
  z->size =0;
  z->alloc = 0;
}


Variant 2:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if ((z->alloc > 0) && (z->data)) {
    ldb_free(z->data);
    z->data = NULL;

  } else {
    z->alloc = 0;
    z->size = 0;
  }

  z->alloc = 0;
  z->size = 0;
}


Variant 3:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (NULL != z && z->alloc > 0 && NULL != z->data) {
    ldb_free(z->data);
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
  }
}


Variant 4:

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0 && NULL != z->data) {
    ldb_free(z->data);
    
  }
  z->data = NULL;
  z->size = z->alloc = 0;
}
