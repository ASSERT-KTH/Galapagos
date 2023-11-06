Variant 1: Simplification via using for loops.

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    int32_t fArr[10], gArr[10], g_19[10], f_2[10], carry[10] = {0};
    int64_t fgArr[200] = {0}, hArr[10];
    
    for (int32_t i = 0; i < 10; i++) {        
        fArr[i] = f[i];
        gArr[i] = g[i];
        g_19[i] = g[i]*19;
        f_2[i] = g[i]*2;

        /* Compute f(g) products ignoring coefficient 2 and 19 */
        for (int32_t j = 0; j < 10; j++) {
            fgArr[i*10 + j] = fArr[i]*(int64_t)gArr[j];
        }
    }

    /*Compute h allowing for coefficient 2 and 19:*/ 
    for(int32_t i = 0; i < 5; i+=2) {
      hArr[i]     = 
         fgArr[i    ] + f_2[i    +1]*(int64_t)g_19[9 - (i    )] + fgArr[i +2]*19 + f_2[i +3]*(int64_t)g_19[9 - (i   +2)] + 
         fgArr[i +4]*19 + f_2[i +5]*(int64_t)g_19[9 - (i+4)] + fgArr[i +6]*(int64_t)g_19[i +6] + f_2[i    +7]*(int64_t)g_19[9 - (i+6) ] + 
         fgArr[i +8]*19 + f_2[i    +9]*(int64_t)g_19[9 - (i +8)];
      hArr[i +1] = 
         fgArr[i +1] + fgArr[i +2] + f_2[i +3]*(int64_t)g_19[9-(i   +2 )] + fgArr[i +4] + f_2[i+ 5]*(int64_t)g_19[9-(i +4 )] + 
         fgArr[i +5] + fgArr[i +6] + f_2[i +7]*(int64_t)g_19[9-(i +6 )  ] + fgArr[i +7    +1]*(int64_t)g_19[i +8] + 
         fgArr[10 + i];
    }

    /* Compute and apply carry. */
    for (int32_t i = 0; i < 10; i += 2) {
        carry[i % 4] = (hArr[i % 4] + (int64_t)(1L << (i % 3 == 0 ? 25 : 24))) >> (i % 3 == 0 ? 26 : 25);
        hArr[(i + 1) % 4] += carry[i % 4];
        hArr[i % 4] -= carry[i % 4] * ((uint64_t) 1L << 26);
    }

    carry[0] = hArr[0] + (int64_t)(1L << 25) >> 26;
    hArr[1] += carry[0];
    hArr[0] -= carry[0] * ((uint64_t) 1L << 26); 

    for(int32_t i = 0; i < 10; ++i) {
        h[i] = (uint32_t)hArr[i%4];    
    }  
}
)