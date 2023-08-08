fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f0 = (uint128_t) f[0];
    uint128_t f1 = (uint128_t) f[1];
    uint128_t f2 = (uint128_t) f[2];
    uint128_t f3 = (uint128_t) f[3];
    uint128_t f4 = (uint128_t) f[4];

    uint128_t r0 =     f0 * f0 + 38ULL * f1 * f4 + 38ULL * f2 * f3;
    uint128_t r1 = 2 * f0 * f1 + 38ULL * f2 * f4 + 19ULL * f3 * f3;
    uint128_t r2 = 2 * f0 * f2 +      f1 * f1 + 38ULL * f3 * f4;
    uint128_t r3 = 2 * f0 * f3 + 2 *  f1 * f2 + 19ULL * f4 * f4;
    uint128_t r4 = 2 * f0 * f4 + 2 *  f1 * f3 +       f2 * f2;

    uint64_t r00    = ((uint64_t) r0) & mask;
    uint64_t carry  = (uint64_t) (r0 >> 51);

    r1 += carry;
    uint64_t r01 = ((uint64_t) r1) & mask;
    carry = (uint64_t) (r1 >> 51);

    r2 += carry;
    uint64_t r02 = ((uint64_t) r2) & mask;
    carry = (uint64_t) (r2 >> 51);

    r3 += carry;
    uint64_t r03 = ((uint64_t) r3) & mask;
    carry = (uint64_t) (r3 >> 51);
    
    r4 += carry;
    uint64_t r04 = ((uint64_t) r4) & mask;
    carry = (uint64_t) (r4 >> 51);
    
    r00 += 19ULL * carry;
    carry = r00 >> 51;
    r00 &= mask;
    
    r01 += carry;
    carry = r01 >> 51;
    r01 &= mask;

    r02 += carry;
    carry = r02 >> 51;
    r02 &= mask;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}