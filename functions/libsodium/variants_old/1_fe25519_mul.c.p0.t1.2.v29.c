fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3] * 2;
    int32_t f4 = f[4];
    int32_t f5 = f[5] * 2;
    int32_t f6 = f[6];
    int32_t f7 = f[7] * 2;
    int32_t f8 = f[8];
    int32_t f9 = f[9] * 2;

    int32_t g0 = g[0];
    int32_t g1 = g[1] * 38;
    int32_t g2 = g[2];
    int32_t g3 = g[3] * 38;
    int32_t g4 = g[4];
    int32_t g5 = g[5] * 38;
    int32_t g6 = g[6];
    int32_t g7 = g[7] * 38;
    int32_t g8 = g[8];
    int32_t g9 = g[9] * 38;

    int64_t h0 = f1 * (int64_t) g9;
    int64_t h1 = f0 * (int64_t) g1 + h0;
    int64_t h2 = f1 * (int64_t) g0 + f0 * (int64_t) g2 + h1;
    int64_t h3 = f0 * (int64_t) g3 + h2;
    int64_t h4 = f1 * (int64_t) g2 + f0 * (int64_t) g4 + h3;
    int64_t h5 = f0 * (int64_t) g5 + h4;
    int64_t h6 = f1 * (int64_t) g4 + f0 * (int64_t) g6 + h5;
    int64_t h7 = f0 * (int64_t) g7 + h6;
    int64_t h8 = f1 * (int64_t) g6 + f0 * (int64_t) g8 + h7;
    int64_t h9 = f0 * (int64_t) g9 + h8;

    h9 = (h9 >> 25) * (int64_t) 19;
    h0 += h9;
    h1 += h0 >> 26;
    h2 += h1 >> 25;
    h3 += h2 >> 26;
    h4 += h3 >> 25;
    h5 += h4 >> 26;
    h6 += h5 >> 25;
    h7 += h6 >> 26;
    h8 += h7 >> 25;
    h9 = h9 + h8 >> 26;

    h[0] = h0 & 0x3FFFFFF;
    h[1] = h1 & 0x1FFFFFF;
    h[2] = h2 & 0x3FFFFFF;
    h[3] = h3 & 0x1FFFFFF;
    h[4] = h4 & 0x3FFFFFF;
    h[5] = h5 & 0x1FFFFFF;
    h[6] = h6 & 0x3FFFFFF;
    h[7] = h7 & 0x1FFFFFF;
    h[8] = h8 & 0x3FFFFFF;
    h[9] = h9 & 0x1FFFFFF;
}