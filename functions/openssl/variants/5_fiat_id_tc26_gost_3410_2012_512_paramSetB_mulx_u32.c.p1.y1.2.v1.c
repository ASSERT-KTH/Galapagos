Variant 1:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
                                                              
    uint64_t product = ((uint64_t) arg1 * arg2);
    *out2 = (uint32_t) (product >> 32);
    *out1 = (uint32_t) (product & UINT32_C(0xffffffff));
    
}


Variant 2:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
                                                                
    uint64_t mult = ((uint64_t) arg1 * arg2);
    *out1 = (uint32_t)(mult & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(mult >> 32);

}
 

Variant 3:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
                                                                
    *out1 = (uint32_t)(((uint64_t) arg1 * arg2) & UINT32_C(0xffffffff));
    *out2 = (uint32_t)(((uint64_t) arg1 * arg2) >> 32);


}
 

Variant 4:

static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(uint32_t *out1,
                                                               uint32_t *out2,
                                                               uint32_t arg1,
                                                               uint32_t arg2) {
 
    uint64_t result_mult = ((uint64_t) arg1 * arg2);
        
    *out1 = (uint32_t) (result_mult % UINT32_C(0x100000000));
    *out2 = (uint32_t) (result_mult / UINT32_C(0x100000000));

}
 