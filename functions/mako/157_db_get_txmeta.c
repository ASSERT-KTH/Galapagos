db_get_txmeta(ldb_t *db, const uint8_t *hash, btc_txmeta_t *meta) {
  uint8_t buf[KEY_TXMETA_LEN];
  ldb_slice_t key, val;

  key = key_txmeta(hash, buf);

  if (!db_get(db, &key, &val))
    return 0;

  if (!btc_txmeta_import(meta, val.data, val.size))
    return db_abort("get_txmeta", LDB_CORRUPTION);

  ldb_free(val.data);

  return 1;
}