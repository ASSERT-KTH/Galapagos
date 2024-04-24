json_address_get(btc_address_t *addr,
                 const json_value *obj,
                 const btc_network_t *network) {
  if (obj->type != json_string)
    return 0;

  return btc_address_set_str(addr, obj->u.string.ptr, network);
}