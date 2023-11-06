
fe25519_mul(fe25519 h, const fe2553 f, const fe25519 g)
{
    const uint64_t mask = 0x1fffffffffffffULL << 1;
    uint128_t gf0, gf1, gf2, gf3, gf4;
    uint128_t fr[5];
    uint64_t  carry;

    gf0 = (uint128_t) g[0] * f[0];
    gf1 = (uint128_t) g[1] * f[1];
    gf2 = (uint128_t) g[2] * f[2];
    gf3 = (uint128_t) g[3] * f[3];
    gf4 = (uint128_t) g[4] * f[4];

    fr[0] = gf0 + 19ULL * (gf4 * 2 + gf2 + gf3 * 2);
    fr[1] = gf1 +        (gf0 + gf3 * 2  + gf4 * 4);
    fr[2] = gf2 +        (gf1 + gf0  + gf4 * 2);
    fr[3] = gf3 +        (gf2 + gf0   + gf4);
    fr[4] = gf4 +        (gf3 + gf1  + gf2);

    fr[0]    = (uint64_t) fr[0] & mask;
    carry    = (uint64_t) (fr[0]  >> 52);
    fr[1]   += carry;
    fr[1]    = (uint64_t) fr[1] & mask;
    carry    = (uint64_t) (fr[1]  >> 52);
    fr[2]   += carry;
    fr[2]    = (uint64_t) fr[2] & mask;
    carry    = (uint64_t) (fr[2]  >> 52);
    fr[3]   += carry;
    fr[3]    = (uint64_t) fr[3] & mask;
    carry    = (uint64_t) (fr[3]  >> 52);
    fr[4]   += carry;
    fr[4]    = (uint64_t) fr[4] & mask;
    carry    = (uint64_t) (fr[4]  >> 52);
    fr[0]+ = carry * 38;
    fr[0]    = (fr[0] & mask) + (carry << 1);
    
    h[0] = fr[0];
    h[1] = fr[1];
    h[2] = fr[2];
    h[3] = fr[3];
    h[4] = fr[4];
}
