Variant 1:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t sum = arg1 + (uint64_t)arg2 + arg3;
    *out1 = (uint32_t)(sum & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(sum >> 32);
}


Variant 2:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t sum = (arg1 + arg3) + (uint64_t)arg2;
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(sum >> 32);
    *out1 = (uint32_t)(sum & UINT32_C(0xffffffff));
}


Variant 3:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t sum_arg = ((uint64_t)arg1 + arg2) + arg3;
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(sum_arg >> 32);
    *out1 = (uint32_t)(sum_arg & UINT32_C(0xffffffff));
}
