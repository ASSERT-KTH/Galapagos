cipher_block_xor(void *_dst, const void *_src1, const void *_src2,
                 size_t blocksize)
{
  byte *dst = _dst;
  const byte *src1 = _src1;
  const byte *src2 = _src2;
  u64 s1[2];
  u64 s2[2];

  if (blocksize == 8)
    {
      buf_put_he64(dst + 0, buf_get_he64(src1 + 0) ^ buf_get_he64(src2 + 0));
    }
  else /* blocksize == 16 */
    {
      s1[0] = buf_get_he64(src1 + 0);
      s1[1] = buf_get_he64(src1 + 8);
      s2[0] = buf_get_he64(src2 + 0);
      s2[1] = buf_get_he64(src2 + 8);
      buf_put_he64(dst + 0, s1[0] ^ s2[0]);
      buf_put_he64(dst + 8, s1[1] ^ s2[1]);
    }
}