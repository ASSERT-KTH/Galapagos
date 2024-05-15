vec_rol_elems(vector2x_u64 v, unsigned int idx)
{
#ifndef WORDS_BIGENDIAN
  return vec_sld (v, v, (16 - (8 * idx)) & 15);
#else
  return vec_sld (v, v, (8 * idx) & 15);
#endif
}