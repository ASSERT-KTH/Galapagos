cipher_block_xor_2dst(void *_dst1, void *_dst2, const void *_src,
                      size_t blocksize)
{
  byte *dst1 = _dst1;
  byte *dst2 = _dst2;
  const byte *src = _src;
  u64 d2[2];
  u64 s[2];

  if (blocksize == 8)
    {
      d2[0] = buf_get_he64(dst2 + 0) ^ buf_get_he64(src + 0);
      buf_put_he64(dst2 + 0, d2[0]);
      buf_put_he64(dst1 + 0, d2[0]);
    }
  else /* blocksize == 16 */
    {
      s[0] = buf_get_he64(src + 0);
      s[1] = buf_get_he64(src + 8);
      d2[0] = buf_get_he64(dst2 + 0);
      d2[1] = buf_get_he64(dst2 + 8);
      d2[0] = d2[0] ^ s[0];
      d2[1] = d2[1] ^ s[1];
      buf_put_he64(dst2 + 0, d2[0]);
      buf_put_he64(dst2 + 8, d2[1]);
      buf_put_he64(dst1 + 0, d2[0]);
      buf_put_he64(dst1 + 8, d2[1]);
    }
}