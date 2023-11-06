Variant 1:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1 = (arg1 + (uint64_t)arg2 + arg3);
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 >> 32);
}


Variant 2:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2, 
    uint32_t arg3) {
    uint64_t x1 = (arg1 + (uint64_t)arg2) + arg3 ;
    *out1 = (uint32_t)(x1 % (UINT32_C(0xffffffff) + 1));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1/(UINT32_C(0xffffffff) + 1));
}


Variant 3:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2, 
    uint32_t arg3) {
    uint64_t sum = (arg1 + (uint64_t)arg2 + arg3 );
    *out1 = sum;
    *out2 = (sum > UINT32_MAX) ? 1 : 0;
}
