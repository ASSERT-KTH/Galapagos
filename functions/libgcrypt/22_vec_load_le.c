vec_load_le(unsigned long offset, const unsigned char *ptr)
{
  vector4x_u32 vec;
  vec = vec_vsx_ld (offset, (const u32 *)ptr);
#ifdef WORDS_BIGENDIAN
  vec = (vector4x_u32)vec_perm((vector16x_u8)vec, (vector16x_u8)vec,
			       le_bswap_const);
#endif
  return vec;
}