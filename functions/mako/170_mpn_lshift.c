mpn_lshift(mp_limb_t *zp, const mp_limb_t *xp, mp_size_t xn, mp_bits_t bits) {
  mp_limb_t c;
  mp_size_t i;

  ASSERT(xn > 0);
  ASSERT(bits > 0 && bits < MP_LIMB_BITS);

  c = xp[xn - 1] >> (MP_LIMB_BITS - bits);

  for (i = xn - 1; i >= 1; i--)
    zp[i] = (xp[i] << bits) | (xp[i - 1] >> (MP_LIMB_BITS - bits));

  zp[0] = xp[0] << bits;

  return c;
}