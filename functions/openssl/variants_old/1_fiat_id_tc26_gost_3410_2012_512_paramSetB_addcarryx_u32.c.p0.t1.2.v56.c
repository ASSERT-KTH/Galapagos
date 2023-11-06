static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {
    uint64_t x1;
    uint32_t x2;
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 x3;
    
    /* Variation: reordered the operations. Made addition with arg3 first, then arg2 */
    x1 = ((arg1 + (uint64_t)arg3) + arg2);
    
    /* Variation: right shift instead to cut off extra bits while overflow */
    x2 = (uint32_t)(x1 >> 0);
    
    /* Variation: logical shift left to extract next bit for x3 while avoiding negative value */
    x3 = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(x1 >> 31);
    
    *out1 = x2;
    *out2 = x3;
}