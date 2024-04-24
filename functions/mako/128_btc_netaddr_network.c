btc_netaddr_network(const btc_netaddr_t *addr) {
  if (!btc_netaddr_is_routable(addr))
    return BTC_IPNET_NONE;

  if (btc_netaddr_is_ipv4(addr))
    return BTC_IPNET_IPV4;

  if (btc_netaddr_is_rfc4380(addr))
    return BTC_IPNET_TEREDO;

  if (btc_netaddr_is_onion(addr))
    return BTC_IPNET_ONION;

  return BTC_IPNET_IPV6;
}