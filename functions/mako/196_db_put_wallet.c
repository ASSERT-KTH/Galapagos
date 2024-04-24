db_put_wallet(ldb_batch_t *batch, const btc_wallet_t *wallet) {
  ldb_slice_t val;
  uint8_t zp[80];

  val.data = zp;
  val.size = btc_wallet_export(zp, wallet);

  ldb_batch_put(batch, &key_wallet, &val);
}