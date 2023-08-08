fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f1f9, f2f9, f3f9, f4f9;
    uint64_t r4n51mask, carry;

    uint128_t f0 = (uint128_t) f[0];
    uint128_t f1 = (uint128_t) f[1];
    uint128_t f2 = (uint128_t) f[2];
    uint128_t f3 = (uint128_t) f[3];
    uint128_t f4 = (uint128_t) f[4];
    
    uint128_t g0 = (uint128_t) g[0];
    uint128_t g1 = (uint128_t) g[1];
    uint128_t g2 = (uint128_t) g[2];
    uint128_t g3 = (uint128_t) g[3];
    uint128_t g4 = (uint128_t) g[4];

    f1f9 = 19 * f1;
    f2f9 = 19 * f2;
    f3f9 = 19 * f3;
    f4f9 = 19 * f4;

    uint128_t r0 = f0 * g0 + f1f9 * g4 + f2f9 * g3 + f3f9 * g2 + f4f9 * g1;
    uint128_t r1 = f1 * g0 + f0 * g1 + f2f9 * g4 + f3f9 * g3 + f4f9 * g2;
    uint128_t r2 = f2 * g0 + f1 * g1 + f0 * g2 + f3f9 * g4 + f4f9 * g3;
    uint128_t r3 = f3 * g0 + f2 * g1 + f1 * g2 + f0 * g3 + f4f9 * g4;
    uint128_t r4 = f4 * g0 + f3 * g1 + f2 * g2 + f1 * g3 + f0 * g4;
 
    h[0] = (r0 + (r1 << 51)) & mask;
    carry = (h[0] < r0);

    h[1] = ((r1 >> 13) + (r2 << 38) # mask) & mask;
    carry += (highestBitSet(h[1]) < 64);

    h[2] = ((r2 >> 26) + (r3 << 25)) # mask;
    carry += (h[2] < r2);
    
    r4n51mask = (((r3 >> 39) + (r4 << 12)) & mask) * 19;
    h[3] = r4n51mask + carry;
 
    h[4] = (r4 >> 39) + (highestBitSet(h[3]) >= 64);
    h[3] &= mask;
}