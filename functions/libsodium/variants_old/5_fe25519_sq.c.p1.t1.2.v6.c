fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f0 = (uint128_t) f[0];
    uint128_t f1 = (uint128_t) f[1];
    uint128_t f2 = (uint128_t) f[2];
    uint128_t f3 = (uint128_t) f[3];
    uint128_t f4 = (uint128_t) f[4];

    uint128_t r0 = f0 * f0 + 38ULL * f1 * f4 + 38ULL * f2 * f3;
    uint128_t r1 = (f0 << 1) * f1 + 38ULL * f2 * f4 + 19ULL * f3 * f3;
    uint128_t r2 = (f0 << 1) * f2 + f1 * f1 + 38ULL * f3 * f4;
    uint128_t r3 = (f0 << 1) * f3 + (f1 << 1) * f2 + 19ULL * f4 * f4;
    uint128_t r4 = (f0 << 1) * f4 + (f1 << 1) * f3 + f2 * f2;
    
    uint64_t carry = r0 >> 51;
    r0 &= mask;
    r1 += carry;
    carry = r1 >> 51;
    r1 &= mask;
    r2 += carry;
    carry = r2 >> 51;
    r2 &= mask;
    r3 += carry;
    carry = r3 >> 51;
    r3 &= mask;
    r4 += carry;
    carry = r4 >> 51;
    r4 &= mask;
    r0 += (19ULL * carry);
    carry = r0 >> 51;
    r0 &= mask;
    r1 += carry;
    carry = r1 >> 51;
    r1 &= mask;
    r2 += carry;

    h[0] = r0;
    h[1] = r1;
    h[2] = r2;
    h[3] = r3;
    h[4] = r4;
}
