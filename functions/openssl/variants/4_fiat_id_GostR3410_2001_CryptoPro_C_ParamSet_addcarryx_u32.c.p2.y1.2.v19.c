static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x3;
    x1 = ((uint64_t)arg2 + (uint64_t)arg1) + arg3;
    x3 = ((x1 >> 32) & UINT32_C(1));
    *out1 = (uint32_t)(x1);
    *out2 = x3;
}