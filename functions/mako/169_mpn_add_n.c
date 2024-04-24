mpn_add_n(mp_limb_t *zp, const mp_limb_t *xp,
                         const mp_limb_t *yp,
                         mp_size_t n) {
  mp_limb_t c = 0;

  switch (n & 3) {
    case 3:
      mp_add_1(*zp, c, *xp, *yp); zp++; xp++; yp++;
    case 2:
      mp_add_1(*zp, c, *xp, *yp); zp++; xp++; yp++;
    case 1:
      mp_add_1(*zp, c, *xp, *yp); zp++; xp++; yp++;
  }

  n >>= 2;

  while (n--) {
    /* [z, c] = x + y + c */
#if defined(mp_add_1x4)
    mp_add_1x4(zp, c, xp, yp);
#else
    mp_add_1(zp[0], c, xp[0], yp[0]);
    mp_add_1(zp[1], c, xp[1], yp[1]);
    mp_add_1(zp[2], c, xp[2], yp[2]);
    mp_add_1(zp[3], c, xp[3], yp[3]);
#endif

    zp += 4;
    xp += 4;
    yp += 4;
  }

  return c;
}