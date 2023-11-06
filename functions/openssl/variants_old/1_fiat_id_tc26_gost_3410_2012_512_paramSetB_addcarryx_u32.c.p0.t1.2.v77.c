static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t y1;
    uint32_t y2;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 y3;
    y1 = ((uint64_t)arg1 + arg2 + arg3); // More readable without parenthesis
    y2 = (y1 & UINT32_C(0xffffffffull)); // Extended constant for clarity
    y3 = (y1 >> 32); // Outcasts are unnecessary. Cleaner to assign the value directly
    if (out1) // Check added to prevent Null Pointer Dereference
        *out1 = y2;
    if (out2) // Check added to prevent Null Pointer Dereference
        *out2 = y3;  
}