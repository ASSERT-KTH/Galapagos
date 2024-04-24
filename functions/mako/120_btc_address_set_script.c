btc_address_set_script(btc_address_t *addr, const btc_script_t *script) {
  const uint8_t *hash, *pub;
  btc_program_t program;
  size_t len;

  btc_address_init(addr);

  if (btc_script_get_program(&program, script))
    return btc_address_set_program(addr, &program);

  if (btc_script_get_p2sh(&hash, script)) {
    addr->type = BTC_ADDRESS_P2SH;
    memcpy(addr->hash, hash, 20);
    return 1;
  }

  if (btc_script_get_p2pkh(&hash, script)) {
    memcpy(addr->hash, hash, 20);
    return 1;
  }

  if (btc_script_get_p2pk(&pub, &len, script)) {
    btc_hash160(addr->hash, pub, len);
    return 1;
  }

  if (btc_script_is_multisig(script)) {
    addr->type = BTC_ADDRESS_P2SH;
    btc_hash160(addr->hash, script->data, script->length);
    return 1;
  }

  return 0;
}