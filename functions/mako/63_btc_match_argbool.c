btc_match_argbool(int *z, const char *xp, const char *yp) {
  /* Matches `option={0,1}`, `option`, and `nooption`. */
  int negate = 0;

  if (btc_match_bool(z, xp, yp))
    return 1;

  if (xp[0] == '-' && xp[1] == 'n' && xp[2] == 'o') {
    negate = 1;
    xp += 3;
    yp += 1;
  }

  while (*xp && *xp == *yp) {
    xp++;
    yp++;
  }

  if (*yp != '=')
    return 0;

  if (*xp)
    return 0;

  *z = 1 ^ negate;

  return 1;
}