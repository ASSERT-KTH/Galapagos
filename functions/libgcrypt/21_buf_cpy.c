buf_cpy(void *_dst, const void *_src, size_t len)
{
  byte *dst = _dst;
  const byte *src = _src;

#if __GNUC__ >= 4
  if (!__builtin_constant_p (len))
    {
      if (UNLIKELY(len == 0))
	return;
      memcpy(_dst, _src, len);
      return;
    }
#endif

  while (len >= sizeof(u64))
    {
      buf_put_he64(dst, buf_get_he64(src));
      dst += sizeof(u64);
      src += sizeof(u64);
      len -= sizeof(u64);
    }

  if (len >= sizeof(u32))
    {
      buf_put_he32(dst, buf_get_he32(src));
      dst += sizeof(u32);
      src += sizeof(u32);
      len -= sizeof(u32);
    }

  /* Handle tail.  */
  for (; len; len--)
    *dst++ = *src++;
}