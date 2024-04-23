json_hash_new(const uint8_t *hash) {
  char str[64 + 1];

  if (hash == NULL)
    return json_null_new();

  btc_hash_export(str, hash);

  return json_string_new_length(64, str);
}