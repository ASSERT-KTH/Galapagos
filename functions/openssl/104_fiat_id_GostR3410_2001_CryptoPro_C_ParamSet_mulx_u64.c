static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_mulx_u64(
    uint64_t *out1, uint64_t *out2, uint64_t arg1, uint64_t arg2) {
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint128 x1;
    uint64_t x2;
    uint64_t x3;
    x1 = ((fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint128)arg1 * arg2);
    x2 = (uint64_t)(x1 & UINT64_C(0xffffffffffffffff));
    x3 = (uint64_t)(x1 >> 64);
    *out1 = x2;
    *out2 = x3;
}