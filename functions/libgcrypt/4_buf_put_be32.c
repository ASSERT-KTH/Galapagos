static inline void buf_put_be32(void *_buf, u32 val)
{
  byte *out = _buf;
  out[0] = val >> 24;
  out[1] = val >> 16;
  out[2] = val >> 8;
  out[3] = val;
}