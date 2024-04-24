mpz_quo_ui(mpz_ptr q, mpz_srcptr n, mp_limb_t d) {
  mp_size_t nn = MP_ABS(n->size);
  mp_limb_t *qp = NULL;
  mp_limb_t r;

  if (d == 0)
    btc_abort(); /* LCOV_EXCL_LINE */

  if (nn == 0) {
    if (q != NULL)
      q->size = 0;

    return 0;
  }

  if (nn == 1 && n->limbs[0] < d) {
    if (q != NULL)
      q->size = 0;

    return n->limbs[0];
  }

  if (q != NULL)
    qp = mpz_grow(q, nn);

  r = mpn_divmod_1(qp, n->limbs, nn, d);

  if (q != NULL) {
    nn -= (qp[nn - 1] == 0);
    q->size = n->size < 0 ? -nn : nn;
  }

  return r;
}