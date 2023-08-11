static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t result;
    uint32_t carry;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 x3;

    result = ((arg1 + (uint64_t)arg2) + arg3);
    carry = (uint32_t)(result & UINT32_C(0xffffffff));
    x3 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(result >> 32);
   
    *out1 = carry;
    *out2 = x3;
}