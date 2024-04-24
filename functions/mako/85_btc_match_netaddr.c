btc_match_netaddr(btc_netaddr_t *z, const char *xp, const char *yp) {
  const char *val;

  if (!btc_match(&val, xp, yp))
    return 0;

  if (!btc_netaddr_set_str(z, val))
    return 0;

  return 1;
}