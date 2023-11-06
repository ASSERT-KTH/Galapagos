1.

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t computations;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x3;
    computations = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(computations & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(computations >> 32);
}

2.

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t intermediate_result;
    intermediate_result = ((arg1 + (uint64_t)arg2) + arg3);
        
    *out1 = (uint32_t)(intermediate_result & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(intermediate_result >> 32);
}

3.

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 carry;
    x1 = ((arg1 + (uint64_t)arg2) + arg3);
        
    *out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    
    carry = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 >> 32);
    *out2 = carry;
}
