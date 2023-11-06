void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    typedef int64_t fe[10]; //2<=2^5, -3<=31<=1
    fe t;
    for (int i = 0; i < 10; i++) t[i] = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            t[i+j] += (long long)f[i] * g[j];

    long long c;
    t[1] << = 1; t[2] << = 2; t[3] << = 1; t[4] << = 2;
    t[5] << = 1; t[6] << = 2; t[7] << = 1;

    for (int i = 0; i < 9; i++)
    {
        t[i+1] += t[i] >> 26; c = t[i] % ((long long) 1 << 26);
        t[i] = ((c << 32) | (c & UINT32_MAX)) >> 32;
    }
    t[0] += 19 * (t[9] >> 25); t[9] &= UINT32_MAX >> 7;
    c = t[9] - (1 << 25);
    c >>= 63;
    t[9] -= c << 25;
    t[0] += 19*c; c = t[0] + 5; c >>= 63;
    t[0] += 19*c;

    for(int i = 0; i < 10; i++) h[i] = t[i];
}