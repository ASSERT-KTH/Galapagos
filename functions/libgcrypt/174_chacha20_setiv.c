chacha20_setiv (void *context, const byte *iv, size_t ivlen)
{
  CHACHA20_context_t *ctx = (CHACHA20_context_t *) context;

  /* draft-nir-cfrg-chacha20-poly1305-02 defines 96-bit and 64-bit nonce. */
  if (iv && ivlen != CHACHA20_MAX_IV_SIZE && ivlen != CHACHA20_MIN_IV_SIZE
      && ivlen != CHACHA20_CTR_SIZE)
    log_info ("WARNING: chacha20_setiv: bad ivlen=%u\n", (u32) ivlen);

  if (iv && (ivlen == CHACHA20_MAX_IV_SIZE || ivlen == CHACHA20_MIN_IV_SIZE
             || ivlen == CHACHA20_CTR_SIZE))
    chacha20_ivsetup (ctx, iv, ivlen);
  else
    chacha20_ivsetup (ctx, NULL, 0);

  /* Reset the unused pad bytes counter.  */
  ctx->unused = 0;
}