fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t a0, a1, a2, a3, a4;
    uint128_t c0, c1, c2, c3, c4;
    uint128_t b1_19, b2_19, b3_19, b4_19;
    uint128_t d0, d1, d2, d3, d4;
    uint64_t  a00, a01, a02, a03, a04;
    uint64_t  trans;

    c0 = (uint128_t) f[0];
    c1 = (uint128_t) f[1];
    c2 = (uint128_t) f[2];
    c3 = (uint128_t) f[3];
    c4 = (uint128_t) f[4];

    d0 = (uint128_t) g[0];
    d1 = (uint128_t) g[1];
    d2 = (uint128_t) g[2];
    d3 = (uint128_t) g[3];
    d4 = (uint128_t) g[4];

    b1_19 = 19ULL * c1;
    b2_19 = 19ULL * c2;
    b3_19 = 19ULL * c3;
    b4_19 = 19ULL * c4;

    a0 = c0 * d0 + b1_19 * d4 + b2_19 * d3 + b3_19 * d2 + b4_19 * d1;
    a1 = c0 * d1 +    c1 * d0 + b2_19 * d4 + b3_19 * d3 + b4_19 * d2;
    a2 = c0 * d2 +    c1 * d1 +    c2 * d0 + b3_19 * d4 + b4_19 * d3;
    a3 = c0 * d3 +    c1 * d2 +    c2 * d1 +    c3 * d0 + b4_19 * d4;
    a4 = c0 * d4 +    c1 * d3 +    c2 * d2 +    c3 * d1 +    c4 * d0;

    a00    = ((uint64_t) a0) & mask;
    trans  = (uint64_t) (a0 >> 51);
    a1    += trans;
    a01    = ((uint64_t) a1) & mask;
    trans  = (uint64_t) (a1 >> 51);
    a2    += trans;
    a02    = ((uint64_t) a2) & mask;
    trans  = (uint64_t) (a2 >> 51);
    a3    += trans;
    a03    = ((uint64_t) a3) & mask;
    trans  = (uint64_t) (a3 >> 51);
    a4    += trans;
    a04    = ((uint64_t) a4) & mask;
    trans  = (uint64_t) (a4 >> 51);
    a00   += 19ULL * trans;
    trans  = a00 >> 51;
    a00   &= mask;
    a01   += trans;
    trans  = a01 >> 51;
    a01   &= mask;
    a02   += trans;

    h[0] = a00;
    h[1] = a01;
    h[2] = a02;
    h[3] = a03;
    h[4] = a04;
}