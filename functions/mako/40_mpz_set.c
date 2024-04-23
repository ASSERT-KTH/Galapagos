mpz_set(mpz_ptr z, mpz_srcptr x) {
  if (z != x) {
    mp_size_t xn = MP_ABS(x->size);
    mp_limb_t *zp = mpz_grow(z, xn);

    mpn_copyi(zp, x->limbs, xn);

    z->size = x->size;
  }
}