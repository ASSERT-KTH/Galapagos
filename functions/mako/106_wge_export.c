wge_export(unsigned char *raw, const wge_t *p, int compact) {
  /* [SEC1] Page 10, Section 2.3.3. */
  if (compact) {
    raw[0] = 0x02 | fe_is_odd(p->y);

    fe_export(raw + 1, p->x);
  } else {
    raw[0] = 0x04;

    fe_export(raw + 1, p->x);
    fe_export(raw + 1 + 32, p->y);
  }

  return p->inf ^ 1;
}