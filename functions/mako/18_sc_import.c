sc_import(sc_t z, const unsigned char *xp) {
  int ret = 1;

  sc_import_raw(z, xp);

  ret &= sc_is_canonical(z);

  sc_select_zero(z, z, ret ^ 1);

  return ret;
}