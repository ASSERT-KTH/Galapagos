Variant 1: 

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
  fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 x0;
  uint64_t x1 = ((uint64_t)arg1 + arg2 + arg3);
  *out1 = (uint32_t)(x1);
  x0 = (x1 >> 32);
  *out2 = x0;
}

Variant 2: 

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
  uint64_t x1 = ((uint64_t)arg1 + arg2 + arg3);
  *out1 = (x1 & UINT32_C(0xffffffff));
  if (x1 > UINT32_MAX) {
    *out2 = 1;
  } else {
    *out2 = 0;
  }
}

Variant 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
  uint64_t x1 = ((uint64_t)arg1 + arg2 + arg3);
  *out1 = x1;
  *out2 = (x1 > UINT32_MAX);
}
