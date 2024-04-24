btc_hex(char *zp, unsigned long long x, int u, const state_t *st) {
  const char *charset = u ? "0123456789ABCDEF" : "0123456789abcdef";
  unsigned long long t = x;
  int n = 0;
  int i;

  do {
    n++;
    t >>= 4;
  } while (t != 0);

  if (st->flags & PRINTF_PRECISION) {
    if (n < st->prec)
      n = st->prec;
  }

  if (st->flags & PRINTF_ALT_FORM)
    n += 2;

  zp[n] = '\0';

  for (i = n - 1; i >= 0; i--) {
    zp[i] = charset[x & 15];
    x >>= 4;
  }

  if (st->flags & PRINTF_ALT_FORM) {
    zp[1] = 'x';
    zp[0] = '0';
  }

  return n;
}