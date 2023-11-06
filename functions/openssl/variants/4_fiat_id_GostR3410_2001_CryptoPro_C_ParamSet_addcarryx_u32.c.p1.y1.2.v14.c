static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32_v1(
    uint32_t *out1, 
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, 
    uint32_t arg2,
    uint32_t arg3) {
    uint64_t total;
    total = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(total & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(total >> 32);
}

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32_v2(
    uint32_t *out1, 
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, 
    uint32_t arg2,
    uint32_t arg3) 
{
    uint64_t addResult = (arg1 + (uint64_t)arg2 + arg3);
    *out1 = (uint32_t)(addResult & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(addResult >> 32);
}


static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32_v3(
    uint32_t *out1, 
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, 
    uint32_t arg2,
    uint32_t arg3) {
    uint64_t temp;
    temp = ((arg1 + (uint64_t)arg2) + arg3);
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(temp >> 32);
    *out1 = (uint32_t)(temp & UINT32_C(0xffffffff));
}

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32_v4(
    uint32_t *out1, 
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, 
    uint32_t arg2,
    uint32_t arg3) {
   
    uint64_t summary = ((arg1 + (uint64_t)arg2) + arg3);
    *out1 = (uint32_t)(summary & UINT32_C(0xffffffff));
    *out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(summary >> 32);
}