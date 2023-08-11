fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0], f0_2  = 2 * f0;
    int32_t f1 = f[1], f1_2  = 2 * f1;
    int32_t f2 = f[2], f2_2  = 2 * f2;
    int32_t f3 = f[3], f3_2  = 2 * f3;
    int32_t f4 = f[4], f4_2  = 2 * f4;
    int32_t f5 = f[5], f5_2  = 2 * f5;
    int32_t f6 = f[6], f6_2  = 2 * f6;
    int32_t f7 = f[7], f7_2  = 2 * f7;
    int32_t f8 = f[8], f8_2  = 2 * f8;
    int32_t f9 = f[9], f9_2  = 2 * f9;
    int32_t two_pow_25 = 1 << 25;
    int32_t two_pow_26 = 1 << 26;

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
    int64_t f1f9_76 = (int64_t)f1_2 * (38 * f9);
    int64_t f2f2    = (int64_t)f2 * f2;
    int64_t f2f3_2  = (int64_t)f2_2 * f3;
    int64_t f2f4_2  = (int64_t)f2_2 * f4;
    
    /* Other terms */

    int64_t carry0 = (h0 + two_pow_25) >> 26; h1 += carry0; h0 -= carry0 * two_pow_26;
    int64_t carry4 = (h4 + two_pow_25) >> 26; h5 += carry4; h4 -= carry4 * two_pow_26;

    int64_t carry1 = (h1 + (int64_t)(1L << 24)) >> 25;
    h2 += carry1;
    h1 -= carry1 * ((uint64_t) 1L << 25);
    int64_t carry5 = (h5 + (int64_t)(1L << 24)) >> 25;
    h6 += carry5;
    h5 -= carry5 * ((uint64_t) 1L << 25);

    /* Other terms */

    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    h[2] = (int32_t) h2;
    h[3] = (int32_t) h3;
    h[4] = (int32_t) h4;
    h[5] = (int32_t) h5;
    h[6] = (int32_t) h6;
    h[7] = (int32_t) h7;
    h[8] = (int32_t) h8;
    h[9] = (int32_t) h9;
}
This variant groups the initialization of each input variable and related computation together, uses `int32_t` instead of hard coding constants, computes square terms (e.g., `f0f0`) first, and takes advantage of inlining each step of atomic computations that include a carry term.