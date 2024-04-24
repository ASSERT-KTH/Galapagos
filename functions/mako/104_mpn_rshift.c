mpn_rshift(mp_limb_t *zp, const mp_limb_t *xp, mp_size_t xn, mp_bits_t bits) {
  mp_limb_t c;
  mp_size_t i;

  ASSERT(xn > 0);
  ASSERT(bits > 0 && bits < MP_LIMB_BITS);

  c = xp[0] << (MP_LIMB_BITS - bits);

  for (i = 0; i < xn - 1; i++)
    zp[i] = (xp[i + 1] << (MP_LIMB_BITS - bits)) | (xp[i] >> bits);

  zp[xn - 1] = xp[xn - 1] >> bits;

  return c >> (MP_LIMB_BITS - bits);
}