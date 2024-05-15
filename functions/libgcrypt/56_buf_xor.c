buf_xor(void *_dst, const void *_src1, const void *_src2, size_t len)
{
  byte *dst = _dst;
  const byte *src1 = _src1;
  const byte *src2 = _src2;

  while (len >= sizeof(u64))
    {
      buf_put_he64(dst, buf_get_he64(src1) ^ buf_get_he64(src2));
      dst += sizeof(u64);
      src1 += sizeof(u64);
      src2 += sizeof(u64);
      len -= sizeof(u64);
    }

  if (len > sizeof(u32))
    {
      buf_put_he32(dst, buf_get_he32(src1) ^ buf_get_he32(src2));
      dst += sizeof(u32);
      src1 += sizeof(u32);
      src2 += sizeof(u32);
      len -= sizeof(u32);
    }

  /* Handle tail.  */
  for (; len; len--)
    *dst++ = *src1++ ^ *src2++;
}