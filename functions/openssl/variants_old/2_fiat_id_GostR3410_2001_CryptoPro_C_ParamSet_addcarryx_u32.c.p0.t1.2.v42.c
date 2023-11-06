static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t temp;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 carry;
    temp = ((uint64_t)arg1 + arg2);
    carry = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(temp > UINT32_MAX ? 1 : 0);
    temp += arg3;
    carry |= (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(temp > UINT32_MAX ? 1 : 0);

    *out1 = (uint32_t)(temp & UINT32_MAX);
    *out2 = carry;
}