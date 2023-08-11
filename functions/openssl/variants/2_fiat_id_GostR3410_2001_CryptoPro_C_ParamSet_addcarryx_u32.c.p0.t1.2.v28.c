static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x4;
    uint32_t x5;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x6;
    x4 = ((uint64_t)arg2 + (uint64_t)arg1) + arg3;
    x5 = (uint32_t)(x4 & UINT32_C(0xffffffff));
    x6 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x4 >> 32);
    
    if(out1!=NULL)
        *out1 = x5;
    if(out2!=NULL)
        *out2 = x6;
}