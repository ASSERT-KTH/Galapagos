fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[9];
    int32_t f1 = f[8];
    int32_t f2 = f[7];
    int32_t f3 = f[6];
    int32_t f4 = f[5];
    int32_t f5 = f[4];
    int32_t f6 = f[3];
    int32_t f7 = f[2];
    int32_t f8 = f[1];
    int32_t f9 = f[0];

    int32_t f0_2  = 2 * f0;
    int32_t f1_2  = 2 * f1;
    int32_t f2_2  = 2 * f2;
    int32_t f3_2  = 2 * f3;
    int32_t f4_2  = 2 * f4;
    int32_t f5_2  = 2 * f5;
    int32_t f6_2  = 2 * f6;
    int32_t f7_2  = 2 * f7;
    int32_t f5_38 = 38 * f5; 
    int32_t f6_19 = 19 * f6; 
    int32_t f7_38 = 38 * f7; 
    int32_t f8_19 = 19 * f8;
    int32_t f9_38 = 38 * f9; 

    /* Operations then Follows */

    int64_t h0 = f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38;

    /* So on and so forth */

    carry0 = (h0 + (int64_t)(1L << 25)) >> 26;
    carry1 = (h1 + (int64_t)(1L << 24)) >> 25;
    /* All Carries Defined */

    carry0 = (h0 + (int64_t)(1L << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1L << 26);

    /* Contributions applied */

    h[9] = (int32_t) h0;
    h[8] = (int32_t) h1;
    h[7] = (int32_t) h2;
    h[6] = (int32_t) h3;
    h[5] = (int32_t) h4;
    h[4] = (int32_t) h5;
    h[3] = (int32_t) h6;
    h[2] = (int32_t) h7;
    h[1] = (int32_t) h8;
    h[0] = (int32_t) h9;
}