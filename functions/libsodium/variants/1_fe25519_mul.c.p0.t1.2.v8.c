fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
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

    int32_t g0 = g[9];
    int32_t g1 = g[8];
    int32_t g2 = g[7];
    int32_t g3 = g[6];
    int32_t g4 = g[5];
    int32_t g5 = g[4];
    int32_t g6 = g[3];
    int32_t g7 = g[2];
    int32_t g8 = g[1];
    int32_t g9 = g[0];

    int32_t g1_19 = 19 * g9; /* 1.959375*2^29 */
    int32_t g2_19 = 19 * g8; /* 1.959375*2^30; still ok */
    int32_t g3_19 = 19 * g7;
    int32_t g4_19 = 19 * g6;
    int32_t g5_19 = 19 * g5;
    int32_t g6_19 = 19 * g4;
    int32_t g7_19 = 19 * g3;
    int32_t g8_19 = 19 * g2;
    int32_t g9_19 = 19 * g1;
    int32_t f1_2  = 2 * f8;
    int32_t f3_2  = 2 * f6;
    int32_t f5_2  = 2 * f4;
    int32_t f7_2  = 2 * f2;
    int32_t f9_2  = 2 * f0;

    /* ... identical code cut for brevity's sake */

    int64_t f1g9_38 = f1_2 * (int64_t) g9_19;
    int64_t f2g0    = f8 * (int64_t) g0;
    int64_t f3g9_38 = f3_2 * (int64_t) g9_19;
    int64_t f4g0    = f4 * (int64_t) g0;
    int64_t f5g9_38 = f5_2 * (int64_t) g9_19;
    int64_t f6g0    = f2 * (int64_t) g0;
    int64_t f9g0    = f0 * (int64_t) g0;
    int64_t f0g9    = f0 * (int64_t) g9;

    int64_t carry9 = (f9g9_38 + (int64_t)(1L << 24)) >> 25;
    h0 += carry9 * 19;
    f9g9_38 -= carry9 * ((uint64_t) 1L << 25);

    int64_t carry0 = (h0 + (int64_t)(1L << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1L << 26);

    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    h[2] = (int32_t) h2;
    h[3] = (int32_t) h3;
    h[4] = (int32_t) h4;
    h[5] = (int32_t) h5;
    h[6] = (int32_t) h6;
    h[7] = (int32_t) h7;
    h[8] = (int32_t) h8;
    h[9] = (int32_t) f9g9_38;
}