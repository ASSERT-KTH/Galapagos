Variant 1:


static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t temp = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(temp & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(temp >> 32);
}


Variant 2:


static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t temp = static_cast<uint64_t>(arg1 + arg2 + arg3);
    *out1 = static_cast<uint32_t>(temp & UINT32_C(0xffffffff));
    *out2 = static_cast<fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1>(temp >> 32);
}


Variant 3:


static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t addition;
    addition = (arg1 + (uint64_t)arg2) + arg3;
    *out1 = (uint32_t)(addition & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(addition >> 32);
}
