void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t f0  = 2 * (int64_t) f[0];
    int64_t f1  = 2 * (int64_t) f[1];
    int64_t f2  = f[2];
    int64_t f3  = 2 * (int64_t) f[3];
    int64_t f4  = f[4];
    int64_t f5  = 2 * f[5];
    int64_t f6  = f[6];
    int64_t f7  = 2 * f[7];
    int64_t f8  = f[8];
    int64_t f9  = 38 * f[9];
    int64_t f10 = 19 * f[10];

    int64_t h0 = f0 * f0 + 38 * (f3 * f3 + f9 * f9) + 19 * (f6 * f6 + f10 * f10);
    h0 = (h0 + (1 << 25)) >> 26;
    int64_t h1 = f1 * f1 + 38 * (f4 * f4) + 19 * (f7 * f7);
    h1 += h0 >> 25;
    h0 &= 0x3ffffff;

    int64_t h2 = f2 * f2 + 38 * (f0 * f5) + 19 * (f1 * f8 + f6 * f9 + f10 * f10);
    h2 = (h2 + (1 << 25)) >> 26;
    int64_t h3 = f3 * f3 + 38 * (f1 * f6) + 19 * (f2 * f9 + f7 * f10);
    h3 += h2 >> 25;
    h2 &= 0x3ffffff;

    int64_t h4 = f4 * f4 + 38 * (f2 * f7) + 19 * (f0 * f9 + f3 * f10);
    h4 = (h4 + (1 << 25)) >> 26;
    int64_t h5 = f5 * f5 + 38 * (f3 * f8) + 19 * (f1 * f10);
    h5 += h4 >> 25;
    h4 &= 0x3ffffff;

    int64_t h6 = f6 * f6 + 38 * (f4 * f9) + 19 * (f2 * f10);
    h6 = (h6 + (1 << 25)) >> 26;
    int64_t h7 = f7 * f7 + 38 * (f0 * f10) + 19 * (f5 * f8);
    h7 += h6 >> 25;
    h6 &= 0x3ffffff;

    int64_t h8 = f8 * f8 + 38 * (f1 * f10) + 19 * (f6 * f9);
    h8 = (h8 + (1 << 25)) >> 26;
    h1 += (h0 = (h1 >> 25)) * 19;
    h0 &= 0x3ffffff;
    int64_t h9 = f9 * f9 + 38 * (f2 * f10) + 19 * (f7 * f8);
    h9 += h8 >> 25;
    h8 &= 0x3ffffff;
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