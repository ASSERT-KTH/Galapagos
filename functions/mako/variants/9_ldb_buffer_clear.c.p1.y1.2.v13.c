1. Checking `z` Nil before proceeding


void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL) {
    if (z->alloc > 0)
      ldb_free(z->data);
    
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
  }
}


2. Giving `NULL` to `ldb_free()` directly. Achieved in standard library.


void ldb_buffer_clear(ldb_buffer_t *z) {
  ldb_free(z->data);
  
  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}


3. Removed NULL being assigned to `z->data` since `ldb_free()` should automatically assign `NULL`. 


void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0) {
    ldb_free(z->data);
  }
  
  z->size = 0;
  z->alloc = 0;
}


4. Storing freed memory location next. Assigning it back after `ldb_free()` has finished running.


void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0) {
    void * tmp_data = z->data;
    ldb_free(z->data);
    z->data = tmp_data;
  }

  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}


5. Incorporating "early return". Typical for methods & saves having to keep things syntactically correct into a scope, like in "if-not".


void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc <= 0) {
    return;
  }
  
  ldb_free(z->data);
  z->data = NULL;
  z->size = 0;
  z->alloc = 0;
}
