btc_sockaddr_import(btc_sockaddr_t *z, const char *xp, int port) {
  btc_sockaddr_init(z);

  if (inet_pton4(xp, z->raw) == 0) {
    z->family = BTC_AF_INET;
    z->port = port;
    return 1;
  }

  if (inet_pton6(xp, z->raw) == 0) {
    z->family = BTC_AF_INET6;
    z->port = port;
    return 1;
  }

  btc_sockaddr_init(z);

  return 0;
}