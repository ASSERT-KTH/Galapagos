static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1_temp;
    uint32_t x2_temp;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x3_temp;

    x1_temp = (uint64_t)arg2 +  (uint64_t)arg3;
    x1_temp += arg1;

    x2_temp = (uint32_t)(x1_temp & UINT32_C(0xffffffff));
    x3_temp = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1_temp >> 32);

    *out1 = x2_temp;
    *out2 = x3_temp;
}