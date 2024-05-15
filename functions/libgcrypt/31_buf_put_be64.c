static inline void buf_put_be64(void *_buf, u64 val)
{
  byte *out = _buf;
  out[0] = val >> 56;
  out[1] = val >> 48;
  out[2] = val >> 40;
  out[3] = val >> 32;
  out[4] = val >> 24;
  out[5] = val >> 16;
  out[6] = val >> 8;
  out[7] = val;
}