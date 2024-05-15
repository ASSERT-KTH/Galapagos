transform ( void *c, const unsigned char *data, size_t nblks )
{
  unsigned int burn;

  do
    {
      burn = transform_blk (c, data);
      data += 32;
    }
  while (--nblks);

  return burn;
}