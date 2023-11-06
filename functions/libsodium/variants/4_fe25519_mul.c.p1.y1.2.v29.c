Variant 1:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t g0 = (uint128_t) g[0], g1 = (uint128_t) g[1], g2 = (uint128_t) g[2], g3 = (uint128_t) g[3], g4 = (uint128_t) g[4];
    uint128_t f0 = (uint128_t) f[0], f1 = 19ULL * ((uint128_t) f[1]), f2 = 19ULL * ((uint128_t) f[2]), f3 = 19ULL * ((uint128_t) f[3]), f4 = 19ULL * ((uint128_t) f[4]);
    uint128_t r0 = f0 * g0 + f1 * g4 + f2 * g3 + f3 * g2 + f4 * g1;
    uint128_t r1 = f0 * g1 + f1/19ULL * g0 + f2 * g4 + f3 * g3 + f4 * g2;
    uint128_t r2 = f0 * g2 + f1/19ULL * g1 + f2/19ULL * g0 + f3 * g4 + f4 * g3;
    uint128_t r3 = f0 * g3 + f1/19ULL * g2 + f2/19ULL * g1 + f3/19ULL * g0 + f4 * g4;
    uint128_t r4 = f0 * g4 + f1/19ULL * g3 + f2/19ULL * g2 + f3/19ULL * g1 + f4/19ULL * g0;

    uint64_t carry = (uint64_t) (r0 >> 51);
    r1 += carry;
    carry = (uint64_t) (r1 >> 51);
    r2 += carry;
    carry = (uint64_t) (r2 >> 51);
    r3 += carry;
    carry = (uint64_t) (r3 >> 51);
    r4 += carry;
    carry = (uint64_t) (r4 >> 51);
    r0  = ((uint64_t) r0 & mask) + 19ULL * carry;
    r1  = ((uint64_t) r1 & mask) + ((r0 >> 51)); r0 &= mask;
    r2  = ((uint64_t) r2 & mask) + ((r1 >> 51)); r1 &= mask;
    r3  = ((uint64_t) r3 & mask) + ((r2 >> 51)); 
    r4  = ((uint64_t) r4 & mask);

    h[0] = r0;
    h[1] = r1;
    h[2] = r2;
    h[3] = r3;
    h[4] = r4;
}


Variant 2:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t f0, f1, f2, f3, f4;
    uint128_t g0, g1, g2, g3, g4;

    f0 = (uint128_t) f[0]; g0 = (uint128_t) g[0];
    f1 = (uint128_t) f[1]; g1 = (uint128_t) g[1];
    f2 = (uint128_t) f[2]; g2 = (uint128_t) g[2];
    f3 = (uint128_t) f[3]; g3 = (uint128_t) g[3];
    f4 = (uint128_t) f[4]; g4 = (uint128_t) g[4];

    uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0 = f0*g0+19ULL*f1*g4+19ULL*f2*g3+19ULL*f3*g2+19ULL*f4*g1;
    uint128_t r1 = f0*g1+f1*g0+19ULL*f2*g4+19ULL*f3*g3+19ULL*f4*g2;
    uint128_t r2 = f0*g2+f1*g1+f2*g0+19ULL*f3*g4+19ULL*f4*g3;
    uint128_t r3 = f0*g3+f1*g2+f2*g1+f3*g0+19ULL*f4*g4;
    uint128_t r4 = f0*g4+f1*g3+f2*g2+f3*g1+f4*g0;
    uint64_t carry = r0 >> 51; r0 = r0 & mask;

    r1 += carry; carry = r1 >> 51; r1 = r1 & mask;
    r2 += carry; carry = r2 >> 51; r2 = r2 & mask;
    r3 += carry; carry = r3 >> 51; r3 = r3 & mask;
    r4 += carry; carry = r4 >> 51; r4 = r4 & mask;
    carry = carry*19; r0 += carry;

    h[0] = r0;
    h[1] = r1;
    h[2] = r2;
    h[3] = r3;
    h[4] = r4;
}
