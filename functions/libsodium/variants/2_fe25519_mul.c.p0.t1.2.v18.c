fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t a0, a1, a2, a3, a4;
    uint128_t b0, b1, b2, b3, b4;
    uint128_t b1_19, b2_19, b3_19, b4_19;
    uint128_t c0, c1, c2, c3, c4;
    uint64_t  a00, a01, a02, a03, a04;
    uint64_t  carry;

    b0 = (uint128_t) f[0];
    b1 = (uint128_t) f[1];
    b2 = (uint128_t) f[2];
    b3 = (uint128_t) f[3];
    b4 = (uint128_t) f[4];

    c0 = (uint128_t) g[0];
    c1 = (uint128_t) g[1];
    c2 = (uint128_t) g[2];
    c3 = (uint128_t) g[3];
    c4 = (uint128_t) g[4];

    b1_19 = 19ULL * b1;
    b2_19 = 19ULL * b2;
    b3_19 = 19ULL * b3;
    b4_19 = 19ULL * b4;

    a0 = b0 * c0 + b1_19 * c4 + b2_19 * c3 + b3_19 * c2 + b4_19 * c1;
    a1 = b0 * c1 +    b1 * c0 + b2_19 * c4 + b3_19 * c3 + b4_19 * c2;
    a2 = b0 * c2 +    b1 * c1 +    b2 * c0 + b3_19 * c4 + b4_19 * c3;
    a3 = b0 * c3 +    b1 * c2 +    b2 * c1 +    b3 * c0 + b4_19 * c4;
    a4 = b0 * c4 +    b1 * c3 +    b2 * c2 +    b3 * c1 +    b4 * c0;

    a00    = ((uint64_t) a0) & mask;
    carry  = (uint64_t) (a0 >> 51);
    a1    += carry;
    a01    = ((uint64_t) a1) & mask;
    carry  = (uint64_t) (a1 >> 51);
    a2    += carry;
    a02    = ((uint64_t) a2) & mask;
    carry  = (uint64_t) (a2 >> 51);
    a3    += carry;
    a03    = ((uint64_t) a3) & mask;
    carry  = (uint64_t) (a3 >> 51);
    a4    += carry;
    a04    = ((uint64_t) a4) & mask;
    carry  = (uint64_t) (a4 >> 51);
    a00   += 19ULL * carry;
    carry  = a00 >> 51;
    a00   &= mask;
    a01   += carry;
    carry  = a01 >> 51;
    a01   &= mask;
    a02   += carry;

    h[0] = a00;
    h[1] = a01;
    h[2] = a02;
    h[3] = a03;
    h[4] = a04;
}