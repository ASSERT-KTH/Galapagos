Alternative 1:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint32_t x2;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x3;
    uint64_t x1 = ((uint64_t)arg1 + arg2 + arg3);
    x2 = (uint32_t)(x1 % ((uint64_t)UNIT32_C(1) << 32));
    x3 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 / (uint64_t)UNIT32_C(1) << 32);
    *out1 = x2;
    *out2 = x3;
}


Alternative 2:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1 = ((uint64_t)arg1 + arg2 + arg3);
    *out1 = (uint32_t)x1;
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 >> 32);
}


Alternative 3:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
  uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
  fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
  uint32_t arg3) {
  uint32_t x2;
  fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x3;
  uint64_t x1 = (arg1 + (arg2 + arg3));
  x2 = (uint32_t) (x1 & UINT32_MAX);
  x3 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1) (x1 > x2);
  *out1 = x2;
  *out2 = x3;
}