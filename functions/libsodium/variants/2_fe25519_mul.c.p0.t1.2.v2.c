fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t i0, i1, i2, i3, i4;
    uint128_t n0, n1, n2, n3, n4;
    uint128_t n1_19, n2_19, n3_19, n4_19;
    uint128_t x0, x1, x2, x3, x4;
    uint64_t  i00, i01, i02, i03, i04;
    uint64_t  carry;

    n0 = (uint128_t) f[0];
    n1 = (uint128_t) f[1];
    n2 = (uint128_t) f[2];
    n3 = (uint128_t) f[3];
    n4 = (uint128_t) f[4];

    x0 = (uint128_t) g[0];
    x1 = (uint128_t) g[1];
    x2 = (uint128_t) g[2];
    x3 = (uint128_t) g[3];
    x4 = (uint128_t) g[4];

    n1_19 = 19ULL * n1;
    n2_19 = 19ULL * n2;
    n3_19 = 19ULL * n3;
    n4_19 = 19ULL * n4;

    i0 = n0 * x0 + n1_19 * x4 + n2_19 * x3 + n3_19 * x2 + n4_19 * x1;
    i1 = n0 * x1 +    n1 * x0 + n2_19 * x4 + n3_19 * x3 + n4_19 * x2;
    i2 = n0 * x2 +    n1 * x1 +    n2 * x0 + n3_19 * x4 + n4_19 * x3;
    i3 = n0 * x3 +    n1 * x2 +    n2 * x1 +    n3 * x0 + n4_19 * x4;
    i4 = n0 * x4 +    n1 * x3 +    n2 * x2 +    n3 * x1 +    n4 * x0;

    i00   = ((uint64_t) i0) & mask;
    carry = (uint64_t) (i0 >> 51);
    i1 += carry;
    i01   = ((uint64_t) i1) & mask;
    carry = (uint64_t) (i1 >> 51);
    i2 += carry;
    i02   = ((uint64_t) i2) & mask;
    carry = (uint64_t) (i2 >> 51);
    i3 += carry;
    i03   = ((uint64_t) i3) & mask;
    carry = (uint64_t) (i3 >> 51);
    i4 += carry;
    i04   = ((uint64_t) i4) & mask;
    carry = (uint64_t) (i4 >> 51);
    i00  += 19ULL * carry;
    carry = i00 >> 51;
    i00  &= mask;
    i01  += carry;
    carry = i01 >> 51;
    i01  &= mask;
    i02  += carry;

    h[0] = i00;
    h[1] = i01;
    h[2] = i02;
    h[3] = i03;
    h[4] = i04;
}