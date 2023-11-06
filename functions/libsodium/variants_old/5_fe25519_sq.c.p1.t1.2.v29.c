void fe25519_sq(fe25519 h, const fe25519 f)
{
    uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0 = 0, r1 = 0, r2 = 0, r3 = 0, r4 = 0;
    uint64_t r00 = 0, r01 = 0, r02 = 0, r03 = 0, r04 = 0;
    uint64_t carry = 0;

    uint128_t f0 = f[0];
    uint128_t f1 = f[1];
    uint128_t f2 = f[2];
    uint128_t f3 = f[3];
    uint128_t f4 = f[4];
    
    r0 = (f0 * f0 + f1 * 38 * f4 + f2 * 38 * f3);
    r1 = (f0 * 2 * f1 + f2 * 38 * f4 + f3 * 19 * f3);
    r2 = (f0 * 2 * f2 + f1 * f1 + f3 * 38 * f4);
    r3 = (f0 * 2 * f3 + f1 * 2 * f2 + f4 * 19 * f4);
    r4 = (f0 * 2 * f4 + f1 * 2 * f3 + f2 * f2);

    r00 = (uint64_t)r0 & mask;
    r01 = (uint64_t)(r1 & mask);
    r02 = (uint64_t)(r2 & mask);
    r03 = (uint64_t)(r3 & mask);
    r04 = (uint64_t)(r4 & mask);

    // normalize result
    carry = r0 >> 51;
    r01 = (uint64_t)(r1 += carry);
    carry = r1 >> 51;
    r02 = (uint64_t)(r2 += carry);
    carry = r2 >> 51;
    r03 = (uint64_t)(r3 += carry);
    carry = r3 >> 51;
    r04 = (uint64_t)(r4 += carry);
    
    carry = r4 >> 51;
    r00 += 19ULL * carry;

    carry = r00 >> 51;
    r00 &= mask;
    r01 = (uint64_t)(r1 += carry);
    carry = r01 >> 51;
    r01 &= mask;
    r02 = (uint64_t)(r2 += carry);

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}