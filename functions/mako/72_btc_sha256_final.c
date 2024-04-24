btc_sha256_final(btc_sha256_t *ctx, uint8_t *out) {
  size_t pos = ctx->size & 63;
  int i;

  ctx->block[pos++] = 0x80;

  if (pos > 56) {
    while (pos < 64)
      ctx->block[pos++] = 0x00;

    sha256_transform(ctx, ctx->block);

    pos = 0;
  }

  while (pos < 56)
    ctx->block[pos++] = 0x00;

  btc_write64be(ctx->block + 56, ctx->size << 3);

  sha256_transform(ctx, ctx->block);

  for (i = 0; i < 8; i++)
    btc_write32be(out + i * 4, ctx->state[i]);
}