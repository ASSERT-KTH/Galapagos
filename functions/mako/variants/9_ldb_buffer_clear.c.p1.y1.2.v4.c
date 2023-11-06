1) Incorporation of condition checking approach 


ldb_buffer_clear (ldb_buffer_t *z) {
    if (z) {
        if (z->alloc > 0) {
            ldb_free (z->data);
            z->alloc = 0;
        }
        z->data = NULL;
        z->size = 0;
    }
}


2) Memory clearly first and then check free operation execution

ldb_buffer_clear(ldb_buffer_t *z) {
  z->data = NULL;
  z->size = 0;
  z->alloc = 0;

  if (z->alloc > 0)
    ldb_free(z->data);
}

3) Inline condition checking approach

ldb_buffer_clear(ldb_buffer_t *z) {
  if (z && z->alloc > 0) {
    ldb_free(z->data);
  }

  if (z) {
    z->data = NULL;
    z->size = 0;
    z->alloc = 0; 
  }
}

4) Nested Condition checking approach

ldb_buffer_clear(ldb_buffer_t *z) {
  if (z) {
    if (z->alloc > 0)
      ldb_free(z->data);
    z->data = NULL;
    z->size = 0;
    z->alloc = 0; 
  }
}
