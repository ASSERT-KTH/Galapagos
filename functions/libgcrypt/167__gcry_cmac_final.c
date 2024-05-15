_gcry_cmac_final (gcry_cipher_hd_t c, gcry_cmac_context_t *ctx)
{
  const unsigned int blocksize = c->spec->blocksize;
  unsigned int count = ctx->mac_unused;
  unsigned int burn;
  byte *subkey;

  /* Tell compiler that we require a cipher with a 64bit or 128 bit block
   * length, to allow better optimization of this function.  */
  if (blocksize > 16 || blocksize < 8 || blocksize & (8 - 1))
    return GPG_ERR_INV_CIPHER_MODE;

  if (count == blocksize)
    subkey = ctx->subkeys[0];        /* K1 */
  else
    {
      subkey = ctx->subkeys[1];      /* K2 */
      ctx->macbuf[count++] = 0x80;
      while (count < blocksize)
        ctx->macbuf[count++] = 0;
    }

  cipher_block_xor (ctx->macbuf, ctx->macbuf, subkey, blocksize);

  cipher_block_xor (ctx->u_iv.iv, ctx->u_iv.iv, ctx->macbuf, blocksize);
  burn = c->spec->encrypt (&c->context.c, ctx->u_iv.iv, ctx->u_iv.iv);
  if (burn)
    _gcry_burn_stack (burn + 4 * sizeof (void *));

  ctx->mac_unused = 0;

  return 0;
}