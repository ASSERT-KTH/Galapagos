btc_match_uint(int *z, const char *xp, const char *yp) {
  if (!btc_match_int(z, xp, yp))
    return 0;

  if (*z < 0)
    return 0;

  return 1;
}