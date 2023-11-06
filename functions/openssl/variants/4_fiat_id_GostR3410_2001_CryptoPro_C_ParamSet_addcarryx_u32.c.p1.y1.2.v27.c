Variant 1:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(x & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x >> 32);
}


Variant 2:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x = ((uint64_t)arg1 + arg2 + arg3);
    *out1 = (x << 0) & UINT32_C(0xffffffff);
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x >> 32);
}


Variant 3:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x = (arg1 + (arg2 + (uint64_t)arg3));
    *out1 = x & UINT32_C(0xffffffff);
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x / UINT32_C(0x100000000));
}
