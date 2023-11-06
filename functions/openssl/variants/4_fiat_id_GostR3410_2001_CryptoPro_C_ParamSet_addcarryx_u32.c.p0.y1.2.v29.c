static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
    uint32_t arg3) 
{
    uint64_t temp;
    uint32_t result1;
    fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 result2;
       
    temp = ((arg1 + (uint64_t)arg2) + arg3);
    result1 = (uint32_t)(temp & UINT32_C(0xffffffff));
    result2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(temp >> 32);
   
    *out1 = result1;
    *out2 = result2;
}