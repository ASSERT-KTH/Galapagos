Variant 1:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2, 
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2, 
    uint32_t arg3) {
    uint64_t result = ((uint64_t)arg1 + arg2) + arg3;
    *out1 = (uint32_t)(result & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(result >> 32);
}


Variant 2:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2, 
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2, uint32_t arg3) {
    uint64_t result;
    result = arg1;
    result += arg2;
    result += arg3;
    *out1 = (uint32_t)(result & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(result >> 32); 
}


Variant 3:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2, 
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2, 
    uint32_t arg3) {
    uint64_t temp = ((uint64_t)arg1 + arg2) + arg3;
    *out1 = (*out1 & 0x00000000) | (uint32_t)(temp & UINT32_C(0xffffffff)); 
    *out2 = (*out2 & 0x00000000) | (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(temp >> 32);
}
