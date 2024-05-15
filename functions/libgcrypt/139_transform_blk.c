transform_blk (void *c, const unsigned char *data)
{
  MD2_CONTEXT *ctx = c;
  int j;

  for (j = 0; j < 16; j++)
    {
      ctx->C[j] ^= S[data[j] ^ ctx->L];
      ctx->L = ctx->C[j];
    }

  permute(ctx->X, data);

  return /* burn stack */ 4 + 5 * sizeof(void*);
}