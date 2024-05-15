static inline u64 buf_get_be64(const void *_buf)
{
  const byte *in = _buf;
  return ((u64)in[0] << 56) | ((u64)in[1] << 48) | \
         ((u64)in[2] << 40) | ((u64)in[3] << 32) | \
         ((u64)in[4] << 24) | ((u64)in[5] << 16) | \
         ((u64)in[6] << 8) | (u64)in[7];
}