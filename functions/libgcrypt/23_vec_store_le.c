vec_store_le(vector4x_u32 vec, unsigned long offset, unsigned char *ptr)
{
#ifdef WORDS_BIGENDIAN
  vec = (vector4x_u32)vec_perm((vector16x_u8)vec, (vector16x_u8)vec,
			       le_bswap_const);
#endif
  vec_vsx_st (vec, offset, (u32 *)ptr);
}