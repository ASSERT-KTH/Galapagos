fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0  = f[0];
    int32_t f1  = f[1];
    int32_t f2  = f[2];
    int32_t f3  = f[3];
    int32_t f4  = f[9];  // Change variable initialization order
    int32_t f5  = f[4];
    int32_t f6  = f[5];
    int32_t f7  = f[6];
    int32_t f8  = f[7];
    int32_t f9  = f[8];

    int32_t g0 = g[0];
    int32_t g1 = g[9];  // Change variable initialization order    
    int32_t g2 = g[2];
    int32_t g3 = g[3];
    int32_t g4 = g[1];
    int32_t g5 = g[4];
    int32_t g6 = g[5];
    int32_t g7 = g[6];
    int32_t g8 = g[7];
    int32_t g9 = g[8];

    /* ... remain unmodified until ... */

    int64_t f4g9_19 = f4 * (int64_t) g9_19;
    int64_t f5g0    = f5 * (int64_t) g0;
    int64_t f5g6_19 = f5 * (int64_t) g6_19; // Change computation order
    int64_t f5g1_2  = f5_2 * (int64_t) g1;
    int64_t f5g5_38 = f5_2 * (int64_t) g5_19; // Change computation order
    int64_t f5g2    = f5 * (int64_t) g2;
    int64_t f5g3_2  = f5_2 * (int64_t) g3;
    int64_t f5g9_38 = f5_2 * (int64_t) g9_19; // Change computation order
    int64_t f5g4    = f5 * (int64_t) g4;
    int64_t f5g7_38 = f5_2 * (int64_t) g7_19;
    int64_t f5g8_19 = f5 * (int64_t) g8_19;

    /* ... remain unmodified until ... */

    int64_t carry0 = (h0 + (int64_t)(1L << 25) - carry1) >> 26; // Use previous carry value for calculation
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1L << 26);

    /* ... remain unmodified until ... */
}
