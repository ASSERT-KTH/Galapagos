_gcry_ctx_get_pointer (gcry_ctx_t ctx, int type)
{
  if (!ctx || memcmp (ctx->magic, CTX_MAGIC, CTX_MAGIC_LEN))
    log_fatal ("bad pointer %p passed to _gcry_ctx_get_pointer\n", ctx);

  if (type == 0)
    return ctx->next;

  if (ctx->type != type)
    log_fatal ("wrong context type %d request for context %p of type %d\n",
               type, ctx, ctx->type);
  return &ctx->u;
}