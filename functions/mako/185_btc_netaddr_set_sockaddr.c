btc_netaddr_set_sockaddr(btc_netaddr_t *z, const btc_sockaddr_t *x) {
  btc_netaddr_init(z);

  if (x->family == BTC_AF_INET) {
    memset(z->raw +  0, 0x00, 10);
    memset(z->raw + 10, 0xff, 2);
    memcpy(z->raw + 12, x->raw, 4);
  } else if (x->family == BTC_AF_INET6) {
    memcpy(z->raw, x->raw, 16);
  } else {
    btc_abort(); /* LCOV_EXCL_LINE */
  }

  z->port = x->port;
}