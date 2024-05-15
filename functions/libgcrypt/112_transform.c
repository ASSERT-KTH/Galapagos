transform ( void *c, const unsigned char *data, size_t nblks )
{
  unsigned int burn;

  do
    {
      burn = transform_blk (c, data);
      data += 64;
    }
  while (--nblks);

  return burn;
}