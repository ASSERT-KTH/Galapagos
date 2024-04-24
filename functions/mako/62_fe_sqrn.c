fe_sqrn(fe_t z, const fe_t x, int n) {
  int i;

  fiat_secp256k1_carry_square(z, x);

  for (i = 1; i < n; i++)
    fiat_secp256k1_carry_square(z, z);
}