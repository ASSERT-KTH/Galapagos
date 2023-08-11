fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fl[10] = {f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]};
    int32_t gl[10] = {g[0], g[1], g[2], g[3], g[4], g[5], g[6], g[7], g[8], g[9]};

    int32_t g1_19 = gl[1] * 19; /* 1.959375*2^29 */
    int32_t g2_19 = gl[2] * 19; /* 1.959375*2^30; still ok */
    int32_t g3_19 = gl[3] * 19;
    int32_t g4_19 = gl[4] * 19;
    int32_t g5_19 = gl[5] * 19;
    int32_t g6_19 = gl[6] * 19;
    int32_t g7_19 = gl[7] * 19;
    int32_t g8_19 = gl[8] * 19;
    int32_t g9_19 = gl[9] * 19;
    int32_t f1_2  = fl[1] * 2;
    int32_t f3_2  = fl[3] * 2;
    int32_t f5_2  = fl[5] * 2;
    int32_t f7_2  = fl[7] * 2;
    int32_t f9_2  = fl[9] * 2;

    int64_t/Fe25519_mulCode/  
    f0g0    = fl[0] * (int64_t) gl[0];
    f0g1    = fl[0] * (int64_t) gl[1];
    ... [etc with the rest of the fg_]
    */
    int64_t h0 = f0g0 + f1g9_38 + 2 * (f2g8_19 + f3g7_38 + f4g6_19) +
                 f5g5_38 + f6g4_19 + 2 * (f7g3_38 + f8g2_19) + f9g1_38;
    ... [etc with the rest of the h_]

    int64_t carry0;
    ... [etc with the rest of the carry_]

    carry0 = (h0 > 0 ? ((h0 + (int64_t)(1L << 25)) >> 26) : ((h0 - (int64_t)(1L << 25)) >> 26));
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1L << 26);
    ... [etc with the rest of the carry_ & carry0 usage, now accounting for negative h values]
    
    h[0] = (int32_t)isWithin(-(1L << 25), h0, (1L << 25) - 1) ? h0 : signOf(h0) * ((1L << 25) - 1);
    ... [etc with the restrictions for h0 values exceeding the original's limits]


}