btc_wide_import(btc_wide_t *z, const char *xp) {
  size_t zn = btc_utf16_size(xp);

  if (zn == 0)
    return 0;

  btc_wide_init(z, zn);

  if (!btc_utf16_write(z->data, zn, xp)) {
    btc_wide_clear(z);
    return 0;
  }

  return 1;
}