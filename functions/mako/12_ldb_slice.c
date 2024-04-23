ldb_slice(const uint8_t *xp, size_t xn) {
  ldb_slice_t z;

  z.data = (uint8_t *)xp;
  z.size = xn;
  z.alloc = 0;

  return z;
}