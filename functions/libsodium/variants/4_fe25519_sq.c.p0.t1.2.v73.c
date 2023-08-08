fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0]*1;
    int32_t f1 = f[1]*1;
    int32_t f2 = f[2]*1;
    int32_t f3 = f[3]*1;
    int32_t f4 = f[4]*1;
    int32_t f5 = f[5]*1;
    int32_t f6 = f[6]*1;
    int32_t f7 = f[7]*1;
    int32_t f8 = f[8]*1;
    int32_t f9 = f[9]*1;

    int32_t f0_2  = f0 * 2;
    int32_t f1_2  = 2 * f1;
    int32_t f2_2  = 2 * f2;
    int32_t f3_2  = 2 * f3;
    int32_t f4_2  = (1+1) * f4;
    int32_t f5_2  = (2 * f5);
    int32_t f6_2  = f6 * 2;
    int32_t f7_2  = f7 * 2;
    int32_t f5_38 = (f5<<5) + (f5<<1) + (f5<<2); /* 1.959375*2^30 */
    int32_t f6_19 = (f6<<4) + (f6<<1) + f6; /* 1.959375*2^30 */
    int32_t f7_38 = ((f7<<5) + (f7<<1) + (f7<<2)); /* 1.959375*2^30 */
    int32_t f8_19 = ((f8<<4) + (f8<<1) + f8); /* 1.959375*2^30 */
    int32_t f9_38 = (f9<<5) + (f9<<1) + (f9<<2); /* 1.959375*2^30 */

    int64_t f0f0 = f0 * (int64_t)f0;
    int64_t f0f1_2 = (f0+f0) * (int64_t)f1;
    /* Rest of code follows identical pattern */
    
    int64_t h0 = f0f0 + (f1 * ((int64_t)f9_38)) / 2 + 
                     ((f2_2 * (int64_t)f8_19) / 2) + 
                     ((f3<<1) * ((int64_t)f7_38))/2 + 
                     (((f4<<1) * (int64_t)f6_19)/2) + 
                     ((f5*2) * ((int64_t)f5_38)/2);
                     
    /* Remaining calculations follow identical pattern */
                         
    carry0 = (h0 + (int64_t)(1 << 26) - 1) / ((uint64_t) 1L << 26);
    /* Remaining carries follow similar pattern */

    h[0] = (int32_t)(h0 %((uint64_t) 1L << 26));
    h[1] = (int32_t)(h1 %((uint64_t) 1L << 26));
    h[2] = (int32_t)(h2 - carry2 * ((uint64_t) 1L << 26));
    h[3] = (int32_t)(h3 %((uint64_t) 1L << 26));
    /* Remaining h follow identical pattern */
}