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
    int32_t f5_38 = 38 * f5;
    int32_t f6_19 = 19 * f6; 
    int32_t f7_38 = 38 * f7;
    int32_t f8_19 = 19 * f8;
    int32_t f9_38 = 38 * f9;

    int64_t f0f0    = (int64_t) f0 * f0;
    int64_t f0f1_2  = (int64_t) f0_2 * f1;
    int64_t f0f2_2  = (int64_t) f0_2 * f2;
    int64_t f0f3_2  = (int64_t) f0_2 * f3;
    int64_t f0f4_2  = (int64_t) f0_2 * f4;
    int64_t f0f5_2  = (int64_t) f0_2 * f5;
    int64_t f0f6_2  = (int64_t) f0_2 * f6;
    int64_t f0f7_2  = (int64_t) f0_2 * f7;
    int64_t f0f8_2  = (int64_t) f0_2 * f8;
    int64_t f0f9_2  = (int64_t) f0_2 * f9;
    int64_t f1f1_2  = (int64_t) f1_2 * f1;
    int64_t f1f2_2  = (int64_t) f1_2 * f2;
    int64_t f1f3_4  = (int64_t) f1_2 * f3_2;
    int64_t f1f4_2  = (int64_t) f1_2 * f4;
    int64_t f1f5_4  = (int64_t) f1_2 * f5_2;
    int64_t f1f6_2  = (int64_t) f1_2 * f6;
    int64_t f1f7_4  = (int64_t) f1_2 * f7_2;
    int64_t f1f8_2  = (int64_t) f1_2 * f8;
    int64_t f1f9_76 = (int64_t) f1_2 * f9_38;

    // Simplify computation
    int64_t f2f3_2  = (int64_t) f2_2 * f3;
    int64_t f3f7_76 = (int64_t) f3_2 * f7_38;
    int64_t f5f9_76 = (int64_t) f5_2 * f9_38;

    int64_t h0 = f0f0 + f1f9_76;
    int64_t carry0 = (h0 + (int64_t)(1L << 25)) >> 26;
    h[0] = (int32_t) (h0 - carry0 * ((uint64_t) 1L << 26));
    h[1] += carry0;

    int64_t h7 = (int64_t) f0_2 * f7 + (int64_t) f1_2 * f6 + (int64_t) f2_2 * f5 + (int64_t) f3_2 * f4;
    int64_t carry7 = (h7 + (int64_t)(1L << 24)) >> 25;
    h[7] = (int32_t) (h7 - carry7 * ((uint64_t) 1L << 25));
    h[8] += carry7;

    // Continue calculation as initial function
    // ...
}