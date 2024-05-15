ocb_input(__m512i *vchecksum, __m128i *voffset, const unsigned char *input,
	  unsigned char *output, const ocb_L_uintptr_t L[4])
{
  __m128i L0 = _mm_loadu_si128((const void *)(uintptr_t)L[0]);
  __m128i L1 = _mm_loadu_si128((const void *)(uintptr_t)L[1]);
  __m128i L2 = _mm_loadu_si128((const void *)(uintptr_t)L[2]);
  __m128i L3 = _mm_loadu_si128((const void *)(uintptr_t)L[3]);
  __m512i vin = _mm512_loadu_epi32 (input);
  __m512i voffsets;

  /* Offset_i = Offset_{i-1} xor L_{ntz(i)} */
  /* Checksum_i = Checksum_{i-1} xor P_i  */
  /* C_i = Offset_i xor ENCIPHER(K, P_i xor Offset_i)  */

  if (vchecksum)
    *vchecksum ^= _mm512_loadu_epi32 (input);

  *voffset ^= L0;
  voffsets = _mm512_castsi128_si512(*voffset);
  *voffset ^= L1;
  voffsets = _mm512_inserti32x4(voffsets, *voffset, 1);
  *voffset ^= L2;
  voffsets = _mm512_inserti32x4(voffsets, *voffset, 2);
  *voffset ^= L3;
  voffsets = _mm512_inserti32x4(voffsets, *voffset, 3);
  _mm512_storeu_epi32 (output, voffsets);

  return vin ^ voffsets;
}