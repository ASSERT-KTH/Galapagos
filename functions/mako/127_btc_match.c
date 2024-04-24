btc_match(const char **zp, const char *xp, const char *yp) {
  while (*xp && *xp == *yp) {
    xp++;
    yp++;
  }

  if (*yp)
    return 0;

  if (!*xp)
    return 0;

  *zp = xp;

  return 1;
}