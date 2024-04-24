ldb_buffer_expand(ldb_buffer_t *z, size_t xn) {
  size_t zn = z->size + xn;

  if (zn > z->alloc) {
    size_t alloc = (z->alloc * 3) / 2;

    if (alloc < zn)
      alloc = zn;

    z->data = (uint8_t *)ldb_realloc(z->data, alloc);
    z->alloc = alloc;
  }

  if (z->alloc == 0)
    return NULL;

  return z->data + z->size;
}