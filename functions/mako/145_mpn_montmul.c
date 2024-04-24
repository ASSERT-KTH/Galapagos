mpn_montmul(mp_limb_t *zp, const mp_limb_t *xp,
                           const mp_limb_t *yp,
                           const mp_limb_t *mp,
                           mp_size_t n,
                           mp_limb_t k,
                           mp_limb_t *scratch) {
  /* Word-by-Word Almost Montgomery Multiplication.
   *
   * [MONT] Algorithm 4, Page 5, Section 3.
   */
  mp_limb_t *tp = scratch;
  mp_limb_t c = mpn_montmul_inner(xp, yp, mp, n, k, tp);

  if (c != 0)
    mpn_sub_n(zp, tp + n, mp, n);
  else
    mpn_copyi(zp, tp + n, n);
}