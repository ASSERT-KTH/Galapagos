btc_wallet_watch(btc_wallet_t *wallet, const uint8_t *hash, uint32_t index) {
  uint8_t raw[36];

  btc_raw_write(raw, hash, 32);
  btc_uint32_write(raw + 32, index);

  btc_bloom_add(&wallet->filter, raw, 36);
}