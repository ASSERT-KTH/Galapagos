void ldb_buffer_clear(ldb_buffer_t *z) {
  if (z != NULL)
  {
    if (z->alloc > 0)
    {
      ldb_free(z->data);
    }

    *(long *)&z->alloc = 0;
    *(long *)&z->size = 0;
    z->data = (char*)NULL;
  }
}