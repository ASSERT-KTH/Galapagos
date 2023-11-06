Sure, below is exactly the same function but slightly manipulated in the code but maintaining exact functionality.


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    uint128_t f0 = (uint128_t) f[0], f1 = (uint128_t) f[1], f2= (uint128_t) f[2],
    f3 = (uint128_t) f[3], f4= (uint128_t) f[4];

    uint128_t g0 = (uint128_t) g[0], g1 = (uint128_t) g[1], g2= (uint128_t) g[2],
    g3 = (uint128_t) g[3], g4= (uint128_t) g[4];
    
    const uint64_t mask = 0x7ffffffffffff;
    uint64_t carry;
    
    uint128_t r0 = f0 * g0 + 19 * f1 * g4 + 19 * f2 * g3 + 19 * f3 * g2 + 19 * f4 * g1,
    r1 = f0 * g1 + f1 * g0 + 19 * f2 * g4 + 19 * f3 * g3 + 19 * f4 * g2,
    r2 = f0 * g2 + f1 * g1 + f2 * g0 + 19 * f3 * g4 + 19 * f4 * g3,
    r3 = f0 * g3 + f1 * g2 + f2 * g1 + f3 * g0 + 19*f4*g4,
    r4 = f0 * g4 + f1 * g3 + f2 * g2 + f3 * g1 + f4 * g0;

    h[0] = r0 & mask;
    h[1] = (r1 += (uint64_t)(r0 >> 51)) & mask;    
    h[2] = (r2 += (uint64_t)(r1 >> 51)) & mask;
    h[3] =   r3  & mask;
    h[4] = (r4  += (uint64_t)(r3 >> 51)) & mask;

    uint64_t x = 19 * (uint64_t)(r4 >> 51);
    carry  = x >> 51;
    h[0] += x & mask;
    h[1] += h[0] >> 51;
    h[2] += h[1] >> 51;

    h[0] &= mask;
    h[1] &= mask;
}

Please note that `fe25519` is an array of `UINT64`.