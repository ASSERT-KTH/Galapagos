btc_sha256_update(btc_sha256_t *ctx, const void *data, size_t len) {
  const uint8_t *raw = (const uint8_t *)data;
  size_t pos = ctx->size & 63;
  size_t want = 64 - pos;

  ctx->size += len;

  if (len >= want) {
    if (pos > 0) {
      memcpy(ctx->block + pos, raw, want);

      raw += want;
      len -= want;
      pos = 0;

      sha256_transform(ctx, ctx->block);
    }

    while (len >= 64) {
      sha256_transform(ctx, raw);
      raw += 64;
      len -= 64;
    }
  }

  if (len > 0)
    memcpy(ctx->block + pos, raw, len);
}