fe25519_add(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t h0 = f[0] + g[0];
    int32_t h1 = f[1] + g[1];
    int32_t h2 = f[2] + g[2];
    int32_t h3 = f[3] + g[3];
    int32_t h4 = f[4] + g[4];
    int32_t h5 = f[5] + g[5];
    int32_t h6 = f[6] + g[6];
    int32_t h7 = f[7] + g[7];
    int32_t h8 = f[8] + g[8];
    int32_t h9 = f[9] + g[9];

    h[0] = h0;
    h[1] = h1;
    h[2] = h2;
    h[3] = h3;
    h[4] = h4;
    h[5] = h5;
    h[6] = h6;
    h[7] = h7;
    h[8] = h8;
    h[9] = h9;
}