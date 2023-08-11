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
    int32_t f8 = f[8];
    int32_t f9 = f[9];

    int32_t f0_2  = f0 << 1;
    int32_t f1_2  = f1 << 1;
    int32_t f2_2  = f2 << 1;
    int32_t f3_2  = f3 << 1;
    int32_t f4_2  = f4 << 1;
    int32_t f5_2  = f5 << 1;
    int32_t f6_2  = f6 << 1;
    int32_t f7_2  = f7 << 1;
    int32_t f5_38 = f5 * 38; 
    int32_t f6_19 = f6 * 19;
    int32_t f7_38 = f7 * 38; 
    int32_t f8_19 = f8 * 19;
    int32_t f9_38 = f9 * 38;

    int64_t f0f0    = (int64_t)f0 * f0;
    int64_t f0f1_2  = (int64_t)f0_2 * f1;
    int64_t f0f2_2  = (int64_t)f0_2 * f2;
    int64_t f0f3_2  = (int64_t)f0_2 * f3;
    int64_t f0f4_2  = (int64_t)f0_2 * f4;
    int64_t f0f5_2  = (int64_t)f0_2 * f5;
    int64_t f0f6_2  = (int64_t)f0_2 * f6;
    int64_t f0f7_2  = (int64_t)f0_2 * f7;
    int64_t f0f8_2  = (int64_t)f0_2 * f8;
    int64_t f0f9_2  = (int64_t)f0_2 * f9;
    int64_t f1f1_2  = (int64_t)f1_2 * f1;
    int64_t f1f2_2  = (int64_t)f1_2 * f2;
    int64_t f1f3_4  = (int64_t)f1_2 * f3_2;
    int64_t f1f4_2  = (int64_t)f1_2 * f4;
    int64_t f1f5_4  = (int64_t)f1_2 * f5_2;
    int64_t f1f6_2  = (int64_t)f1_2 * f6;
    int64_t f1f7_4  = (int64_t)f1_2 * f7_2;
    int64_t f1f8_2  = (int64_t)f1_2 * f8;
    int64_t f1f9_76 = (int64_t)f1_2 * f9_38;
    int64_t f2f2    = (int64_t)f2 * f2;
    int64_t f2f3_2  = (int64_t)f2_2 * f3;
    // ... avoided putting the rest of the code to reduce text length

    int64_t carry0 = ((int64_t)h0 + (1L << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 << 26;
    int64_t carry4 = ((int64_t)h4 + (1L << 25)) >> 26;
    h5 += carry4;
    h4 -= carry4 << 26;
    // ... avoided putting the rest of the code to reduce text length

    h[0] = (int32_t) (h0 & ((1L << 26) - 1));
    h[1] = (int32_t) h1;
    h[2] = (int32_t) h2;
    h[3] = (int32_t) h3;
    h[4] = (int32_t) (h4 & ((1L << 26) - 1));
    h[5] = (int32_t) h5;
    h[6] = (int32_t) h6;
    h[7] = (int32_t) h7;
    h[8] = (int32_t) h8;
    h[9] = (int32_t) (h9 & ((1L << 25) - 1));
}