_gcry_cmac_reset (gcry_cmac_context_t *ctx)
{
  char tmp_buf[sizeof(ctx->subkeys)];

  /* Only keep subkeys when reseting context. */

  buf_cpy (tmp_buf, ctx->subkeys, sizeof(ctx->subkeys));
  memset (ctx, 0, sizeof(*ctx));
  buf_cpy (ctx->subkeys, tmp_buf, sizeof(ctx->subkeys));
  wipememory (tmp_buf, sizeof(tmp_buf));
}