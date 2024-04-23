btc_uint32_update(btc_hash256_t *ctx, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint8_t tmp[4];
  btc_uint32_write(tmp, x);
  btc_hash256_update(ctx, tmp, 4);
#else
  btc_hash256_value(ctx, x);
#endif
}