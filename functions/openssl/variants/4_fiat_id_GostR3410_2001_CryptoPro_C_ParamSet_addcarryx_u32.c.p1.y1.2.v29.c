Variant 1:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
	uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
	fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
	uint32_t arg3) {

	uint64_t x1 = ((arg1 + (uint64_t)arg2) + arg3);
	
	*out1 = (uint32_t)(x1 & UINT32_C(0xffffffff));
	*out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 >> 32);
}

Variant 2:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
	uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
	fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
	uint32_t arg3) {

	uint64_t x1 = ((uint64_t)(arg1 + arg2) + arg3);
	
	*out1 = (uint32_t)(x1 % ((uint64_t)UINT32_MAX + 1));
	*out2 = (fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1)(x1 / ((uint64_t)UINT32_MAX + 1));
}

Variant 3:

static void fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
	uint32_t *out1, fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 *out2,
	fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 arg1, uint32_t arg2,
	uint32_t arg3) {
	
	*out1 = *out2 = 0;
	uint64_t x1 = arg1;

	x1 += arg2;
	if (x1 < arg2) {
		(*out2)++;
	}
 	
	x1 += arg3;
	if (x1 < arg3) {
		(*out2)++;
	}
 	
	*out1 = x1;
}
