btc_hash256_root(uint8_t *out, const void *left, const void *right) {
  btc_hash256_t ctx;
  btc_hash256_init(&ctx);
  btc_hash256_update(&ctx, left, 32);
  btc_hash256_update(&ctx, right, 32);
  btc_hash256_final(&ctx, out);
}