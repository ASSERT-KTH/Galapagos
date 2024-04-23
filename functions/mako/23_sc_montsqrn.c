sc_montsqrn(sc_t z, const sc_t x, int n) {
  int i;

  ASSERT(n > 0);

  sc_montsqr(z, x);

  for (i = 1; i < n; i++)
    sc_montsqr(z, z);
}