cipher_block_add(void *_dstsrc, unsigned int add, size_t blocksize)
{
  byte *dstsrc = _dstsrc;
  u64 s[2];

  if (blocksize == 8)
    {
      buf_put_be64(dstsrc + 0, buf_get_be64(dstsrc + 0) + add);
    }
  else /* blocksize == 16 */
    {
      s[0] = buf_get_be64(dstsrc + 8);
      s[1] = buf_get_be64(dstsrc + 0);
      s[0] += add;
      s[1] += (s[0] < add);
      buf_put_be64(dstsrc + 8, s[0]);
      buf_put_be64(dstsrc + 0, s[1]);
    }
}