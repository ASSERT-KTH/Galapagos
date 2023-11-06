static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    uint64_t addResult;

    // Perform the add operations
    addResult = (uint64_t)arg1 + arg2;
    addResult += arg3;

    // Extract 32 LS bits
    uint32_t x2 = (uint32_t)(addResult & UINT32_C(0xffffffff));

    // Extract 32 MS bits
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x3 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(addResult >> 32);

    // Set the output parameters
    *out1 = x2;
    *out2 = x3;
}