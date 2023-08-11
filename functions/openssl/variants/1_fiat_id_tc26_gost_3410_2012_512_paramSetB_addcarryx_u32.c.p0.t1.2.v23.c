Here is a variant of the function that maintains the same behavior but slightly alters the manner:


static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2, 
    uint32_t arg3) {
    uint64_t x1;
    uint32_t x2;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 x3;
    x1 = ((uint64_t)arg1 + arg2);
    x1 += arg3;
    x2 = (uint32_t)(x1 % (uint64_t)UINT32_C(0x100000000));
    x3 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(x1 / (uint64_t)UINT32_C(0x100000000));
    *out1 = x2;
    *out2 = x3;
}
 

Although the raw binary transformations differ, this preserves the output and functionality arguably through a more readable code variant. The 32-bit unsigned integer type naturally wraps over at `0xffffffff + 1`, so `UINT32_C(0x100000000)` is used as the divisor or modulus operand in relation to carry flags.