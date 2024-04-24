btc_netaddr_is_local(const btc_netaddr_t *addr) {
  if (btc_netaddr_is_ipv4(addr)) {
    if (addr->raw[12] == 127 || addr->raw[12] == 0)
      return 1;
    return 0;
  }

  if (btc_memcmp(addr->raw, btc_local_ip, sizeof(btc_local_ip)) == 0)
    return 1;

  return 0;
}