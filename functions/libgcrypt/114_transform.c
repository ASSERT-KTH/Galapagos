transform (void *ctx, const unsigned char *data, size_t nblks)
{
  SM3_CONTEXT *hd = ctx;
  unsigned int burn;

  do
    {
      burn = transform_blk (hd, data);
      data += 64;
    }
  while (--nblks);

  return burn;
}