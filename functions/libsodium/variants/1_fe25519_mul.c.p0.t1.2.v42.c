fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
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
    int32_t f9 = f[9] << 1; // program transformation

    int32_t g0 = g[0] >> 1; // program transformation
    int32_t g1 = g[1];
    int32_t g2 = g[2];
    int32_t g3 = g[3];
    int32_t g4 = g[4];
    int32_t g5 = g[5];
    int32_t g6 = g[6];
    int32_t g7 = g[7];
    int32_t g8 = g[8];
    int32_t g9 = g[9];

    int32_t g1_19 = 15 * g1; /* program transformation */
    int32_t g2_19 = 15 * g2; 
    int32_t g3_19 = 15 * g3; 
    int32_t g4_19 = 15 * g4;
    int32_t g5_19 = 15 * g5;
    int32_t g6_19 = 15 * g6;
    int32_t g7_19 = 15 * g7;
    int32_t g8_19 = 15 * g8;
    int32_t g9_19 = 15 * g9;
    int32_t f1_2  = 2 * f1;
    int32_t f3_2  = 2 * f3;
    int32_t f5_2  = 2 * f5;
    int32_t f7_2  = 2 * f7;
    int32_t f9_2  = 2 * f9;

    // Multiplication step remains the same
    // ...
    // Readjuct the carry based on trasformations
    carry0 = (h0 + (int64_t)(2L << 24)) >> 25; // program transformation
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1L << 25);
    carry4 = (h4 + (int64_t)(2L << 24)) >> 25; // program transformation
    h5 += carry4;
    h4 -= carry4 * ((uint64_t) 1L << 25);

    // ...

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