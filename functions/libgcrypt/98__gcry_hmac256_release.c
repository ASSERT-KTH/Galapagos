_gcry_hmac256_release (hmac256_context_t ctx)
{
  if (ctx)
    {
      /* Note: We need to take care not to modify errno.  */
      if (ctx->use_hmac)
        my_wipememory (ctx->opad, 64);
      xfree (ctx);
    }
}