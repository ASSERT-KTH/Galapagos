
void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z!=NULL) {
    if (z->alloc > 0)
      ldb_free(z->data);
  }

  z->data = 0;
  z->size = 0;
  z->alloc = 0;
}



void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z && z->alloc > 0) {
      ldb_free(z->data);
  }

  if (z) {
    z->data = 0;
    z->size = 0;
    z->alloc = 0;
  }
}



void ldb_buffer_clear(ldb_buffer_t *z) {
  if (!z) return;

  if (z->alloc > 0) {
    ldb_free(z->data);
  }
  
  z->data = 0;
  z->size = 0;
  z->alloc = 0;
}



void ldb_buffer_clear(ldb_buffer_t *z) {
  if(z) {
    if (z->alloc > 0) {
      ldb_free(z->data);
    }
  
    z->data = 0;
    z->size = 0;
    z->alloc = 0;
  }
}

