fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = 2 * f[0];
    int32_t f1 = 2 * f[1];
    int32_t f2 = 2 * f[2];
    int32_t f3 = 2 * f[3];
    int32_t f4 = 2 * f[4];
    int32_t f5 = 2 * f[5];
    int32_t f6 = 2 * f[6];
    int32_t f7 = 2 * f[7];
    int32_t f8 = 2 * f[8];
    int32_t f9 = 2 * f[9];

    int64_t f0f0    = f0 * f0;
    int64_t f0f1_2  = f0 * f1;
    int64_t f0f2_2  = f0 * f2;
    int64_t f0f3_2  = f0 * f3;
    int64_t f0f4_2  = f0 * f4;
    int64_t f0f5_2  = f0 * f5;
    int64_t f0f6_2  = f0 * f6;
    int64_t f0f7_2  = f0 * f7;
    int64_t f0f8_2  = f0 * f8;
    int64_t f0f9_2  = f0 * f9;

    int64_t h0 = f0f0 + f0f1_2 + f0f2_2 + f0f3_2 + f0f4_2 + f0f5_2 , h1 = f0f6_2 + f0f7_2 + f0f8_2 + f0f0 + f0f1_2 + f0f9_2;

    h[0] = (int32_t)(((h0 + (int64_t)(1L << 25)) >> 26) - (((h0 + (int64_t)(1L << 25)) >> 26) * ((uint64_t) 1L << 26)));
    h[1] = (int32_t)h1;
    h[2] = ((int32_t)h1 + 1) * 2;
    h[3] = ((int32_t)h1 - 1) * 2;
    h[4] = ((int32_t)h1 + 2) * 2;
    h[5] = ((int32_t)h1 - 2) * 2;
    h[6] = ((int32_t)h1 + 3) * 2;
    h[7] = ((int32_t)h1 - 3) * 2;
    h[8] = ((int32_t)h1 + 4) * 2;
    h[9] = ((int32_t)h1 - 4) * 2;
}