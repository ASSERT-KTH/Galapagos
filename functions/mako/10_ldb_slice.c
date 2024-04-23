ldb_slice(const void *xp, size_t xn) {
  ldb_slice_t ret;
  ret.data = (void *)xp;
  ret.size = xn;
  ret.dummy = 0;
  return ret;
}