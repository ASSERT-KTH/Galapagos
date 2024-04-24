btc_signed(char *zp, long long x, const state_t *st) {
  int n = 0;

  if (x < 0) {
    *zp++ = '-';

#if defined(LLONG_MIN) && defined(ULLONG_MAX)
    if (x == LLONG_MIN)
      return 1 + btc_unsigned(zp, ULLONG_MAX / 2 + 1, st);
#endif

    return 1 + btc_unsigned(zp, -x, st);
  }

  if (st->flags & PRINTF_BLANK_POSITIVE) {
    *zp++ = ' ';
    n++;
  } else if (st->flags & PRINTF_PLUS_MINUS) {
    *zp++ = '+';
    n++;
  }

  return n + btc_unsigned(zp, x, st);
}