state_need(state_t *st, size_t n) {
  if (st->flags & PRINTF_PRECISION) {
    if (n < (size_t)st->prec)
      n = st->prec;
  } else if (st->flags & PRINTF_WIDTH) {
    if (n < (size_t)st->width)
      n = st->width;
  }

  if (st->flags & (PRINTF_BLANK_POSITIVE | PRINTF_PLUS_MINUS))
    n += 1;

  if (st->flags & PRINTF_ALT_FORM)
    n += 2;

  state_grow(st, n);
}