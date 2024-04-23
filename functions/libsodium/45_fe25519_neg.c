fe25519_neg(fe25519 h, const fe25519 f)
{
    int32_t h0 = -f[0];
    int32_t h1 = -f[1];
    int32_t h2 = -f[2];
    int32_t h3 = -f[3];
    int32_t h4 = -f[4];
    int32_t h5 = -f[5];
    int32_t h6 = -f[6];
    int32_t h7 = -f[7];
    int32_t h8 = -f[8];
    int32_t h9 = -f[9];

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