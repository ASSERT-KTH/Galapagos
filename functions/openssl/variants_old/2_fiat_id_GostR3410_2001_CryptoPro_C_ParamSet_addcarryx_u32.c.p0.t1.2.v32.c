static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint32_t x4;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x5;
    uint64_t x6 = (arg1 + (uint64_t)arg3);
    uint64_t x1 = (x6 + arg2);
    x4 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    x5 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 >> 32);
    *out1 = x4;
    *out2 = x5;
}
