static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t y1;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 y3;
    uint32_t y2;
    y1 = ((uint64_t)arg1 + arg2 + arg3);
    y2 = (uint32_t)(y1 % UINT32_MAX);
    y3 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(y1 / UINT32_MAX);
    *out1 = y2;
    *out2 = y3;
}