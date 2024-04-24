ldb_wide_import(ldb_wide_t *z, const char *xp) {
  size_t zn = ldb_utf16_size(xp);

  if (zn == 0)
    return 0;

  ldb_wide_init(z, zn);

  if (!ldb_utf16_write(z->data, zn, xp)) {
    ldb_wide_clear(z);
    return 0;
  }

  return 1;
}