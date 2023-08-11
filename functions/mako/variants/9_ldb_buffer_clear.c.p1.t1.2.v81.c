void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL)
  {
    if (z->alloc > 0) {
      lbl_free(z->data);
      z->data = NULL;
    }

    z->size = 0;
    z->alloc = 0;
  }
}