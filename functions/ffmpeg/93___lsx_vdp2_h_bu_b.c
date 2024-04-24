static inline __m128i __lsx_vdp2_h_bu_b(__m128i in_h, __m128i in_l) {
  __m128i out;

  out = __lsx_vmulwev_h_bu_b(in_h, in_l);
  out = __lsx_vmaddwod_h_bu_b(out, in_h, in_l);
  return out;
}