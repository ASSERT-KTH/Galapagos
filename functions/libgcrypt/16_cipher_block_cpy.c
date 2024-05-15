cipher_block_cpy(void *_dst, const void *_src, size_t blocksize)
{
  byte *dst = _dst;
  const byte *src = _src;
  u64 s[2];

  if (blocksize == 8)
    {
      buf_put_he64(dst + 0, buf_get_he64(src + 0));
    }
  else /* blocksize == 16 */
    {
      s[0] = buf_get_he64(src + 0);
      s[1] = buf_get_he64(src + 8);
      buf_put_he64(dst + 0, s[0]);
      buf_put_he64(dst + 8, s[1]);
    }
}