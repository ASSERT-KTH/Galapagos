static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    uint32_t x2;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x3;
    x1 = ((uint64_t)arg1 + arg2 + arg3); // Change the cast for argument 1 from post-addition to pre-addition
    x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    *out1 = x2;
    x3 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 >> 32);
    *out2 = x3 != 0 ? 1 : 0; // Explicitly convert the x3's value to binary (0 or 1). This may prevent issues if for any reason the ">>" operation didn't produce zero.
}
