ldb_vector_clear(ldb_vector_t *z) {
  if (z->alloc > 0)
    ldb_free(z->items);

  z->items = NULL;
  z->length = 0;
  z->alloc = 0;
}