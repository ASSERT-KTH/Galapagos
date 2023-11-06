Variant 1: Rearranging statements within 'if' condition

void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0) {
    z->alloc = 0;
    z->size = 0;
    ldb_free(z->data);
    z->data = NULL;
  }
}


Variant 2: Holding the allocations into temporary holders

void ldb_buffer_clear(ldb_buffer_t *z) {
  void *tmp_data = z->data;
  size_t tmp_alloc = z->alloc;
  
  z->data = NULL;
  z->size = 0;
  z->alloc = 0;

  if (tmp_alloc > 0)
    ldb_free(tmp_data);
}


Variant 3: Applying ternary operation

void ldb_buffer_clear(ldb_buffer_t *z) {
  void *tmp_data = z->alloc > 0 ? z->data : NULL;
  
  z->data = NULL;
  z->size = 0;
  z->alloc = 0;

  if (tmp_data)
    ldb_free(tmp_data);
}


Variant 4: Adjust an early return

void ldb_buffer_clear(ldb_buffer_t *z) {
  if(z->alloc <= 0) {
    return;
  }

  ldb_free(z->data);

  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}


Variant 5: Ensuring no function reentrancy hampers freed 'z'

void ldb_buffer_clear(ldb_buffer_t *z) {
  z->data = NULL;
  z->size = 0;

  if (z->alloc > 0) {
    z->alloc = 0;
    ldb_free(z->data);
  }  
}
