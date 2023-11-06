fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;
    uint64_t mask = 0x7ffffffffffffULL;

    uint128_t h0 = f[0];
    uint128_t h1 = f[1];
    uint128_t h2 = f[2];
    uint128_t h3 = f[3];
    uint128_t h4 = f[4];

    uint128_t z0 = g[0];
    uint128_t z1 = g[1];
    uint128_t z2 = g[2];
    uint128_t z3 = g[3];
    uint128_t z4 = g[4];

    h1 = 19ULL * h1;
    h2 = 19ULL * h2;
    h3 = 19ULL * h3;
    h4 = 19ULL * h4;

    uint128_t g0 = h0 * z0 + h1 * z4 + h2 * z3 + h3 * z2 + h4 * z1;
    uint128_t g1 = h0 * z1 + f[1] * z0 + h2 * z4 + h3 * z3 + h4 * z2;
    uint128_t g2 = h0 * z2 + f[1] * z1 + f[2] * z0 + h3 * z4 + h4 * z3;
    uint128_t g3 = h0 * z3 + f[1] * z2 + f[2] * z1 + f[3] * z0 + h4 * z4;
    uint128_t g4 = h0 * z4 + f[1] * z3 + f[2] * z2 + f[3] * z1 + f[4] * z0;

    r00   = (g0 & mask);
    carry = r00 >> 51;
    r00  += g0 & mask;
    g1   += carry;

    r01   = (g1 & mask);
    carry = r01 >> 51;
    r01  += g1 & mask;
    g2   += carry;

    r02   = (g2 & mask);
    carry = r02 >> 51;
    r02  += g2 & mask;
    g3   += carry;

    r03   = (g3 & mask);
    carry = r03 >> 51;
    r03  += g3 & mask;
    g4   += carry;

    r04   = (g4 & mask);
    carry = r04 >> 51;
    r04  += g4 & mask;
    g0   += 19 * carry;

    r00   = g0 & mask;
    carry = g0 >> 51;
    r01  +=  carry;

    r01   = r01 & mask;
    carry =  r01 >> 51;
    r02  +=  carry;
    
       h[0] = r00;
       h[1] = r01;
       h[2] = r02;
       h[3] = r03;
       h[4] = r04;
}