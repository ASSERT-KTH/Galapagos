// Alternative 1:
// Using single line operation and condition
static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, 
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, 
    uint32_t arg2,
    uint32_t arg3) {

    uint64_t tmp = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(tmp & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(tmp >> 32);
}


// Alternative 2:
// Division by zero handling
static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, 
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, 
    uint32_t arg2,
    uint32_t arg3) {

    uint64_t x1 = ((arg1 + (uint64_t)arg2) + arg3);
    
    if (x1 != 0) {
        uint32_t x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));
        fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x3 = 
        (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 >> 32);
        *out1 = x2;
        *out2 = x3;
    }
}


// Alternative 3:
// Code Hoisting and Loop Invariant
static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, 
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, 
    uint32_t arg2,
    uint32_t arg3) {

    const uint64_t DXOverY = UINT32_C(0xffffffff);

    uint64_t x1 = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(x1 & DXOverY);
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 >> 32);
}