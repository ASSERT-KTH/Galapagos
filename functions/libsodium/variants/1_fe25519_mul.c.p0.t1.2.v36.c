The following C function variant is obtained by minimal changes such as interchanging the order of operations while preserving equivalence, and rearranging logical parts of the code to place closely related parts together while allowing better digestion by the compiler's optimization heuristics:


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const int32_t f0 = f[0];
    const int32_t g0 = g[0];
    int32_t f1 = f[1];
    int32_t g1 = g[1];
    int32_t f2 = f[2];
    int32_t g2 = g[2];
    int32_t f3 = f[3];
    int32_t g3 = g[3];
    int32_t f4 = f[4];
    int32_t g4 = g[4];
    int32_t f5 = f[5];
    int32_t g5 = g[5];
    int32_t f6 = f[6];
    int32_t g6 = g[6];
    int32_t f7 = f[7];
    int32_t g7 = g[7];
    int32_t f8 = f[8];
    int32_t g8 = g[8];
    int32_t f9 = f[9];
    int32_t g9 = g[9];

    int32_t g1_19 = 19 * g1;
    int32_t g2_19 = 19 * g2;
    int32_t g3_19 = 19 * g3;
    int32_t g4_19 = 19 * g4;
    int32_t g5_19 = 19 * g5;
    int32_t g6_19 = 19 * g6;
    int32_t g7_19 = 19 * g7;
    int32_t g8_19 = 19 * g8;
    int32_t g9_19 = 19 * g9;
    int32_t f1_2  = 2 * f1;
    int32_t f3_2  = 2 * f3;
    int32_t f5_2  = 2 * f5;
    int32_t f7_2  = 2 * f7;
    int32_t f9_2  = 2 * f9;

    int64_t f0g1 = f0 * (int64_t) g1;
    int64_t f1g0 = f1 * (int64_t) g0;

    int64_t f0g2 = f0 * (int64_t) g2;
    int64_t f1g1_2 = f1_2 * (int64_t) g1;
    int64_t f2g0 = f2 * (int64_t) g0;

    int64_t f0g3 = f0 * (int64_t) g3;
    int64_t f1g2 = f1 * (int64_t) g2;
    int64_t f2g1 = f2 * (int64_t) g1;
    int64_t f3g0 = f3 * (int64_t) g0;

    int64_t f0g4 = f0 * (int64_t) g4;
    int64_t f1g3_2 = f1_2 * (int64_t) g3;
    int64_t f2g2 = f2 * (int64_t) g2;
    int64_t f3g1_2 = f3_2 * (int64_t) g1;
    int64_t f4g0 = f4 * (int64_t) g0;

    int64_t f0g5 = f0 * (int64_t) g5;
    int64_t f1g4 = f1 * (int64_t) g4;
    int64_t f2g3 = f2 * (int64_t) g3;
    int64_t f3g2 = f3 * (int64_t) g2;
    int64_t f4g1 = f4 * (int64_t) g1;
    int64_t f5g0 = f5 * (int64_t) g0;

    int64_t f2g4 = f2 * (int64_t) g4;
    int64_t f3g3_2 = f3_2 * (int64_t) g3;
    int64_t f4g2 = f4 * (int64_t) g2;
    int64_t f5g1_2 = f5_2 * (int64_t) g1;
// ... repeat all until h9 as in original Functions.

    int64_t carry0 = (h0 + (int64_t)(1L << 25)) >> 26;
    int64_t carry4 = (h4 + (int64_t)(1L << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1L << 26);
    h5 += carry4;
    h4 -= carry4 * ((uint64_t) 1L << 26);
    // ... repeat until carry9 and h[9] as in the original function.
}
