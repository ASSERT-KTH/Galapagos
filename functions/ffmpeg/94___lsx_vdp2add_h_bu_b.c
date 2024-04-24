static inline __m128i __lsx_vdp2add_h_bu_b(__m128i in_c, __m128i in_h,
                                           __m128i in_l) {
  __m128i out;

  out = __lsx_vmaddwev_h_bu_b(in_c, in_h, in_l);
  out = __lsx_vmaddwod_h_bu_b(out, in_h, in_l);
  return out;
}