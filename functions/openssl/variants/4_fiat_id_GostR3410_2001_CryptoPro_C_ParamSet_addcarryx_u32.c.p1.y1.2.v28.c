Variant 1:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t arg_aggregate;
    uint32_t lower_bits;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 upper_bits;

    arg_aggregate = ((arg1 + (uint64_t)arg2) + arg3);
    lower_bits = (uint32_t)(arg_aggregate & UINT32_C(0xffffffff));
    upper_bits = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(arg_aggregate >> 32);

    *out1 = lower_bits;
    *out2 = upper_bits;
}

Variant 2:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t temp;
    
    temp = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(temp & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(temp >> 32);
}


Variant 3: 

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {

    uint64_t x1, low_part;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 high_part;

    x1 = ((arg1 + (uint64_t)arg2) + arg3);
    low_part = (uint32_t)(x1 & UINT32_C(0xffffffff));
    high_part = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 >> 32);

    *out1 = low_part;
    *out2 = high_part;
}
