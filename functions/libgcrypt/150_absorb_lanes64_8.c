static inline void absorb_lanes64_8(u64 *dst, const byte *in)
{
  dst[0] ^= buf_get_le64(in + 8 * 0);
  dst[1] ^= buf_get_le64(in + 8 * 1);
  dst[2] ^= buf_get_le64(in + 8 * 2);
  dst[3] ^= buf_get_le64(in + 8 * 3);
  dst[4] ^= buf_get_le64(in + 8 * 4);
  dst[5] ^= buf_get_le64(in + 8 * 5);
  dst[6] ^= buf_get_le64(in + 8 * 6);
  dst[7] ^= buf_get_le64(in + 8 * 7);
}