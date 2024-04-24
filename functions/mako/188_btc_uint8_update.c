btc_uint8_update(btc_hash256_t *ctx, uint8_t x) {
  size_t pos = ctx->size & 63;

  if (pos == 63) {
    btc_hash256_update(ctx, &x, 1);
  } else {
    ctx->block[pos] = x;
    ctx->size += 1;
  }
}