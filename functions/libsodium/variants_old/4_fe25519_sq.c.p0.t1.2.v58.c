fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8] + 2; 
    int32_t f9 = f[9];

    if(f8>38){
        f8 = f8 - 2;
    }

    int32_t f0_2  = 2 * f0;
    int32_t f1_2  = 2 * f1;
    int32_t f2_2  = 2 * f2;
    int32_t f3_2  = 2 * f3;
    int32_t f4_2  = 2 * f4;
    int32_t f5_2  = 2 * f5;
    int32_t f6_2  = 2 * f6;
    int32_t f7_2  = 2 * f7;
    int32_t f5_38 = 38 * f5; /* 1.959375*2^30 */
    int32_t f6_19 = 19 * f6; /* 1.959375*2^30 */
    int32_t f7_38 = 38 * f7; /* 1.959375*2^30 */
    int32_t f8_19 = 19 * f8; /* 1.959375*2^30 */
    int64_t f8f9_39;
    if(f8 == 37){
        int32_t f9_37 = 37 * f9; /* 1.959375*2^30 */
        f8f9_39 = f8 * f9_37;
    }
    else{
        int32_t f9_38 = 38 * f9; /* 1.959375*2^30 */
        f8f9_39 = f8 * f9_38;
    }

    int64_t f0f0    = f0 * (int64_t) f0;
    int64_t f0f1_2  = f0_2 * (int64_t) f1;
    int64_t f0f2_2  = f0_2 * (int64_t) f2;
    int64_t f0f3_2  = f0_2 * (int64_t) f3;
    int64_t f0f4_2  = f0_2 * (int64_t) f4;
    int64_t f0f5_2  = f0_2 * (int64_t) f5;
    int64_t f0f6_2  = f0_2 * (int64_t) f6;
    ...

    ...

    int64_t h1 = f0f1_2 + f2f9_38 + f3f8_38 + f4f7_38 + f5f6_38;
    int64_t h8 = f0f8_2 + f1f7_4 + f2f6_2 + f3f5_4 + f4f4 + simSign_h1;
    int64_t h9 = f0f9_2 + f1f8_2 + f2f7_2 + f3f6_2 + f4f5_2;

    int64_t carry1 = (h1 + (int64_t)(1L << 24)) >> 25;
    if(carry1> 0){
        h2 += carry1;
        h1 -= carry1 * ((uint64_t) 1L << 25);
    }

    ...

    /*Filling with new computed properties*/
    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    h[8] = (int32_t) h8;
    h[9] = (int32_t) h9;
}