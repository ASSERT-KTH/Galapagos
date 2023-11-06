static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    // Initializing default values first 
    uint64_t x1 = 0;
    uint32_t x2 = 0;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x3 = 0;

    // X1 still uses same formula as per the original code
    x1 = ((arg1 + (uint64_t)arg2) + arg3);

    // Switched position of *out1 = x2 and x3 calculation
    // But still using same calculation for x2
    *out1 = x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));

    // Assignment to out2 now incorporates assignment of x3
    *out2 = x3 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 >> 32);
}
