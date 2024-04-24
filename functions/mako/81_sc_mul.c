sc_mul(sc_t z, const sc_t x, const sc_t y) {
  mp_limb_t zp[REDUCE_LIMBS]; /* 160 bytes */
  mp_size_t zn = SCALAR_LIMBS * 2;

  mpn_mul_n(zp, x, y, SCALAR_LIMBS);

  mpn_zero(zp + zn, REDUCE_LIMBS - zn);

  sc_reduce(z, zp);
}