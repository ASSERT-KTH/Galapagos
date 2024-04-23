static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_mulx_u32(
    uint32_t *out1, uint32_t *out2, uint32_t arg1, uint32_t arg2) {
    uint64_t x1;
    uint32_t x2;
    uint32_t x3;
    x1 = ((uint64_t)arg1 * arg2);
    x2 = (uint32_t)(x1 & UINT32_C(0xffffffff));
    x3 = (uint32_t)(x1 >> 32);
    *out1 = x2;
    *out2 = x3;
}