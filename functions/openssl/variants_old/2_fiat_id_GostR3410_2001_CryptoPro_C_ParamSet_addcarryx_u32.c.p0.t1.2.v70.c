static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    uint32_t x2;
    int x4;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x3;
    x4 = (arg1 > UINT32_C(0xffffffff) - arg2); // overflow
    x1 = ((uint64_t)arg2 + arg3);
    x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    x3 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 >> 32);
    if(x4){
      x3 = x3 + 1; // integer overflow adjustment
    }
    *out1 = x2;
    *out2 = x3;
}