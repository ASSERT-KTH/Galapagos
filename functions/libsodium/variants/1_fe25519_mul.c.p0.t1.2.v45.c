fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4];
    int32_t f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];

    int32_t g0 = g[0], g1 = g[1], g2 = g[2], g3 = g[3], g4 = g[4];
    int32_t g5 = g[5], g6 = g[6], g7 = g[7], g8 = g[8], g9 = g[9];

    const int64_t a19 = 19;
    const int64_t multiplier = 2;
    int64_t h[10];

    for (int i = 0; i < 10; i++)
    {
        h[i] = f[i];
    }

    int64_t f0g0 = f0 * g0, f1g1 = f1 * g1, f2g2 = f2 * g2, f3g3 = f3 * g3;

    h[2] += f4 * g4;
    h[3] += f5 * g5;
    h[4] += f6 * g6;
    h[5] += f7 * g7 * a19;
    h[6] += f8 * g8 * a19;
    h[7] += f9 * g9 * a19;

    for (int i = 0; i < 8; i++)
    {
        h[i] -= h[i + 1] * a19;
    }

    h[8] *= a19 + multiplier;
    h[9] *= multiplier;
        
    for (int i = 0; i < 10; i++)
    {
        h[i] &= ((int64_t)0x3FFFFFFF);
    }
        
    h[0] = f0g0 + f1g1 * a19 + f2g2 * multiplier;
    h[1] = f0g0 + f1g1 + f2g2 * a19 + f3g3 * multiplier + h[1];

    for (int i = 0; i < 10; i++)
    {
        h[i] += h[i];
    }

    int64_t carry = 0;
    for (int i = 0; i < 10; i++)
    {
        h[i] += carry;
        carry = h[i] >> 25;
        h[i] &= (0x1FFFFFFF);
    }

    fe25519_carry(h);
}
