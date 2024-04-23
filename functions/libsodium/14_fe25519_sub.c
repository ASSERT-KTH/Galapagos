fe25519_sub(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t h0, h1, h2, h3, h4;

    h0 = g[0];
    h1 = g[1];
    h2 = g[2];
    h3 = g[3];
    h4 = g[4];

    h1 += h0 >> 51;
    h0 &= mask;
    h2 += h1 >> 51;
    h1 &= mask;
    h3 += h2 >> 51;
    h2 &= mask;
    h4 += h3 >> 51;
    h3 &= mask;
    h0 += 19ULL * (h4 >> 51);
    h4 &= mask;

    h0 = (f[0] + 0xfffffffffffdaULL) - h0;
    h1 = (f[1] + 0xffffffffffffeULL) - h1;
    h2 = (f[2] + 0xffffffffffffeULL) - h2;
    h3 = (f[3] + 0xffffffffffffeULL) - h3;
    h4 = (f[4] + 0xffffffffffffeULL) - h4;

    h[0] = h0;
    h[1] = h1;
    h[2] = h2;
    h[3] = h3;
    h[4] = h4;
}