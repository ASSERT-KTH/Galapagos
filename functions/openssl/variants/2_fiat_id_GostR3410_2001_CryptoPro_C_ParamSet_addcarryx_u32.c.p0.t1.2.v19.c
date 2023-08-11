static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    
    uint64_t x4;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x5;
    x4 = ((uint64_t)arg1 + arg2 + arg3);
    *out1 = (uint32_t)(x4 % UINT64_C(0x100000000));
    x5 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x4 > UINT32_MAX);
    *out2 = x5;
}