_gcry_ctx_release (gcry_ctx_t ctx)
{
  gcry_ctx_t ctx_next;

 again:
  if (!ctx)
    return;
  if (memcmp (ctx->magic, CTX_MAGIC, CTX_MAGIC_LEN))
    log_fatal ("bad pointer %p passed to gcry_ctx_relase\n", ctx);
  switch (ctx->type)
    {
    case CONTEXT_TYPE_EC:
    case CONTEXT_TYPE_SINGLE_DATA:
      break;
    default:
      log_fatal ("bad context type %d detected in gcry_ctx_relase\n",
                 ctx->type);
      break;
    }
  if (ctx->deinit)
    ctx->deinit (&ctx->u);
  ctx_next = ctx->next;
  xfree (ctx);
  ctx = ctx_next;
  goto again;
}