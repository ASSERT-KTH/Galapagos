static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t v1;
    uint32_t v2;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 v3;
    v1 = ((uint64_t)arg1 + arg2 + arg3);
    v2 = (uint32_t)(v1 % (UINT32_MAX + 1ULL));
    v3 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(v1 / (UINT32_MAX + 1ULL));
    *out1 = v2;
    *out2 = v3;
}