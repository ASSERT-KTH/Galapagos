btc_match_bool(int *z, const char *xp, const char *yp) {
  /* Matches `option={0,1}` */
  const char *val;

  if (!btc_match(&val, xp, yp))
    return 0;

  if (val[0] != '0' && val[0] != '1')
    return 0;

  if (val[1] != '\0')
    return 0;

  *z = val[0] - '0';

  return 1;
}