json_address_new(const btc_address_t *addr, const btc_network_t *network) {
  char str[BTC_ADDRESS_MAXLEN + 1];

  btc_address_get_str(str, addr, network);

  return json_string_new(str);
}