static void fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(unsigned int *out1,
                                                                unsigned int *out2,
                                                                unsigned int arg1,
                                                                unsigned int arg2) {
    unsigned long long x1;
    unsigned int x2;
    unsigned int x3;
    x1 = ((unsigned long long)arg1 * arg2);
    x2 = (unsigned int)(x1 % UINT32_MAX);
    x3 = (unsigned int)(x1 / UINT32_MAX);
    *out1 = x2;
    *out2 = x3;
}