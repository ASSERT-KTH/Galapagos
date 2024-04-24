btc_unsigned(char *zp, unsigned long long x, const state_t *st) {
  int n = btc_uint_size(x);
  int i;

  if (st->flags & PRINTF_PRECISION) {
    if (n < st->prec)
      n = st->prec;
  }

  zp[n] = '\0';

  for (i = n - 1; i >= 0; i--) {
    zp[i] = '0' + (int)(x % 10);
    x /= 10;
  }

  return n;
}