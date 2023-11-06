fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fComponents[10], gComponents[10], gComponents_19[10], fComponents_2[6];
    int64_t f_g[49];

    /* Initialization of arrays fComponents and gComponents */
    for(int i = 0; i < 10; i++) {
        fComponents[i] = f[i];
        gComponents[i] = g[i];
    }

    /* Assign multiples of 2 and 19 */
    for(int i = 1; i < 10; i+=2) {
        gComponents_19[i] = 19 * gComponents[i];
    }
    for(int i = 1; i <= 9; i+=2) {
        fComponents_2[i/2]  = 2 * fComponents[i];
    }

    // Calculate f_i * g_j
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(i + j == 1 || i + j == 3 || i + j == 5 || i + j == 7 || i + j == 9)
                if(i > j)
                    f_g[i*5 + j/2] = fComponents_2[j/2] * (int64_t)(i % 2 == 0 ? gComponents[i] : gComponents_19[i]);
                else
                    f_g[i*5 + j/2] = fComponents_2[i/2] * (int64_t)(j % 2 == 0 ? gComponents[j] : gComponents_19[j]);
            else
                f_g[i*5 + j/2] = fComponents[i] * (int64_t)(j % 2 == 0 ? gComponents[j] : gComponents_19[j]);
        }
    }

    int64_t hInt[10], carry[10];
    for(int i = 0; i < 10; i++) {
        hInt[i] = 0;
        /* Compute h[i] */ 

        for(int j = 0; j <= i; j++)
            hInt[i]+=f_g[j*5+(i-j)/2];

        for(int j = i+1; j < 10; j++)
            hInt[i]+=38*f_g[j*5+(i-j)/2];
    }


    /* carry operations */
    int carry_shift[10] = {26, 25, 26, 25, 26, 25, 26, 25, 26, 25};
    uint64_t carry_mult[10] = {1L<<26, 1L<<25, 1L<<26, 1L<<25, 1L<<26, 1L<<25, 1L<<26, 1L<<25, 1L<<26, 1L<<25};

    for (int i = 0; i < 9; i++)
    {
        carry[i] = (hInt[i] + (int64_t)(1L<< carry_shift[i])) >> carry_shift[i+1];
        hInt[i+1] += carry[i];
        hInt[i] -= carry[i] * carry_mult[i];

    }

    carry[9] = (hInt[9] + (int64_t)(1L << carry_shift[9])) >> carry_shift[0];
    hInt[0] += carry[9] * 19;
    hInt[9] -= carry[9] * carry_mult[9];
    carry[0] = (hInt[0] + (int64_t)(1L << carry_shift[0])) >> carry_shift[1];
    hInt[1] += carry[0];
    hInt[0] -= carry[0] * carry_mult[0];
    

    for(int i = 0; i < 10; i++)
        h[i] = (int32_t) hInt[i];

}
