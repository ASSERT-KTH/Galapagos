static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    
    uint64_t sum;
    
    sum = ((uint64_t)arg1 + arg2 + arg3);

    *out1 = ((uint32_t)(sum & 0xffffffff));
    *out2 = (sum > UINT32_MAX);

}
