transform_blk (void *ctx, const unsigned char *data)
{
  GOSTR3411_CONTEXT *hd = ctx;
  u32 m[8];
  unsigned int burn;
  int i;

  for (i = 0; i < 8; i++)
    m[i] = buf_get_le32(data + i*4);
  burn = do_hash_step (hd, hd->h, m);
  do_add (hd->sigma, m);

  return /* burn_stack */ burn + 3 * sizeof(void*) + 32 + 2 * sizeof(void*);
}