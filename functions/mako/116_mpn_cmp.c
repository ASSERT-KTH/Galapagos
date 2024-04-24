mpn_cmp(const mp_limb_t *xp, const mp_limb_t *yp, mp_size_t n) {
  mp_size_t i;

  for (i = n - 1; i >= 0; i--) {
    if (xp[i] != yp[i])
      return xp[i] < yp[i] ? -1 : 1;
  }

  return 0;
}