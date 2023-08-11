static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x4;
    uint32_t x5;
    uint64_t x6;
    x6 = (arg1 + (uint64_t)arg2);
    x5 = (uint32_t) (x6 & UINT32_C(0xffffffff));
    x4 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1) (x6 >> 32);
    x5 = x5 + arg3;
    if ((fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1) (x5 < arg3)){
        x4 = x4 + 1;
    }    
    *out1 = x5;
    *out2 = x4;
}