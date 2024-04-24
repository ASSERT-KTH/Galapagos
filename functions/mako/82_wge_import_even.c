wge_import_even(wge_t *r, const unsigned char *raw) {
  /* [BIP340] "Specification". */
  int ret = 1;
  fe_t x;

  ret &= fe_import(x, raw);
  ret &= wge_set_x(r, x, 0);

  return ret;
}