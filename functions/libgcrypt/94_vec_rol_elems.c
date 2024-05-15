vec_rol_elems(vector4x_u32 v, unsigned int idx)
{
#ifndef WORDS_BIGENDIAN
  return vec_sld (v, v, (16 - (4 * idx)) & 15);
#else
  return vec_sld (v, v, (4 * idx) & 15);
#endif
}