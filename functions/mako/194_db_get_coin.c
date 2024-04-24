db_get_coin(ldb_t *db, const uint8_t *hash, uint32_t index, btc_coin_t **coin) {
  uint8_t buf[KEY_COIN_LEN];
  ldb_slice_t key, val;

  key = key_coin(hash, index, buf);

  if (!db_get(db, &key, &val))
    return 0;

  *coin = btc_credit_decode(val.data, val.size);

  if (*coin == NULL)
    return db_abort("db_get_coin", LDB_CORRUPTION);

  ldb_free(val.data);

  return 1;
}