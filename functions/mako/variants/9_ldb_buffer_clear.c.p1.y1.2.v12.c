Variant 1: Void Type for argument check

ldb_buffer_clear(ldb_buffer_t * z) {
  if (z != NULL) {
    if (z->alloc > 0)
      ldb_free(z->data);
      
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
  }
}


Variant 2: Integrating all the assignments into a single line.

ldb_buffer_clear(ldb_buffer_t *z) {
  if (z->alloc > 0)
    ldb_free(z->data);
  z->data = NULL, z->size = z->alloc = 0;
}


Variant 3: Reducing 'if' nesting using Logical AND operator

ldb_buffer_clear(ldb_buffer_t *z) {
  if ((z != NULL) && (z->alloc > 0))
    ldb_free(z->data), z->data = NULL, z->size = z->alloc = 0;
}
