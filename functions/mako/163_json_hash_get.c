json_hash_get(uint8_t *hash, const json_value *obj) {
  if (obj->type != json_string)
    return 0;

  if (obj->u.string.length != 64)
    return 0;

  return btc_base16le_decode(hash, obj->u.string.ptr, 64);
}