static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x3;
    x1 = ((uint64_t)arg2 + arg3 + arg1);
    *out1 = (uint32_t)(x1 % UINT32_MAX);
    x3 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)((x1 - *out1) / UINT32_MAX);
    *out2 = x3;
}