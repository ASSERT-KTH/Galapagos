mpz_mul_ui(mpz_ptr z, mpz_srcptr x, mp_limb_t y) {
  mp_size_t xn, zn;
  mp_limb_t *zp;

  if (x->size == 0 || y == 0) {
    z->size = 0;
    return;
  }

  xn = MP_ABS(x->size);
  zn = xn + 1;
  zp = mpz_grow(z, zn);

  zp[xn] = mpn_mul_1(zp, x->limbs, xn, y);

  zn -= (zp[zn - 1] == 0);

  z->size = x->size < 0 ? -zn : zn;
}