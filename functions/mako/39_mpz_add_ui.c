mpz_add_ui(mpz_ptr z, mpz_srcptr x, mp_limb_t y) {
  mp_size_t zn;

  if (x->size >= 0) {
    /* x + y == x + y */
    zn = mpz_addabs_ui(z, x, y);
  } else {
    if (mpz_cmpabs_ui(x, y) < 0) {
      /* (-x) + y == y - x */
      z->limbs[0] = y - x->limbs[0];
      zn = 1;
    } else {
      /* (-x) + y == -(x - y) */
      zn = -mpz_subabs_ui(z, x, y);
    }
  }

  z->size = zn;
}