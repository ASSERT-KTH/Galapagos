mpz_cmp(mpz_srcptr x, mpz_srcptr y) {
  if (x->size != y->size)
    return x->size < y->size ? -1 : 1;

  if (x->size < 0)
    return -mpn_cmp(x->limbs, y->limbs, -x->size);

  return mpn_cmp(x->limbs, y->limbs, x->size);
}