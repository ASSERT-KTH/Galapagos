btc_script_is_program(const btc_script_t *script) {
  if (script->length < 4 || script->length > 42)
    return 0;

  if (script->data[0] != BTC_OP_0) {
    if (script->data[0] < BTC_OP_1 || script->data[0] > BTC_OP_16)
      return 0;
  }

  if ((size_t)script->data[1] + 2 != script->length)
    return 0;

  return 1;
}