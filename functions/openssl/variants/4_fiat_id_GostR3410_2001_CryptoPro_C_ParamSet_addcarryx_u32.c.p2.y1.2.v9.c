static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t sum;
    uint32_t overflow;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 carry;
    sum = ((arg1 + (uint64_t)arg2) + arg3);
    overflow = (uint32_t)(sum & UINT32_C(0xffffffff));
    carry = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(sum >> 32);
    *out1 = overflow;
    *out2 = carry;
}