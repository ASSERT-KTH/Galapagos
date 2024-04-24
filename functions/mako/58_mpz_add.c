mpz_add(mpz_ptr z, mpz_srcptr x, mpz_srcptr y) {
  mp_size_t zn;

  if ((x->size ^ y->size) >= 0) {
    /* x + y == x + y */
    /* (-x) + (-y) == -(x + y) */
    zn = mpz_addabs(z, x, y);
  } else {
    int cmp = mpz_cmpabs(x, y);

    if (cmp == 0) {
      /* x + (-x) == 0 */
      /* (-x) + x == 0 */
      zn = 0;
    } else if (cmp < 0) {
      /* x + (-y) == -(y - x) */
      /* (-x) + y == y - x */
      zn = -mpz_subabs(z, y, x);
    } else {
      /* x + (-y) == x - y */
      /* (-x) + y == -(x - y) */
      zn = mpz_subabs(z, x, y);
    }
  }

  z->size = x->size < 0 ? -zn : zn;
}