fe25519_add(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint64_t h0 = f[0] + g[0];
    uint64_t h1 = f[1] + g[1];
    uint64_t h2 = f[2] + g[2];
    uint64_t h3 = f[3] + g[3];
    uint64_t h4 = f[4] + g[4];

    h[0] = h0;
    h[1] = h1;
    h[2] = h2;
    h[3] = h3;
    h[4] = h4;
}