mpz_bitlen(mpz_srcptr x) {
  mp_size_t xn = MP_ABS(x->size);

  if (xn == 0)
    return 0;

  return xn * MP_LIMB_BITS - mp_clz(x->limbs[xn - 1]);
}