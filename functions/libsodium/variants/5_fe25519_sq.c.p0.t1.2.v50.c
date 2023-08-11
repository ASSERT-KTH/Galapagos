fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t a0, a1, a2, a3, a4;
    uint128_t b0, b1, b2, b3, b4;
    uint128_t b0_2, b1_2, b1_38, b2_38, b3_38, b3_19, b4_19;
    uint64_t  a00, a01, a02, a03, a04;
    uint64_t  overflow;

    b0 = (uint128_t) f[0];
    b1 = (uint128_t) f[1];
    b2 = (uint128_t) f[2];
    b3 = (uint128_t) f[3];
    b4 = (uint128_t) f[4];

    b0_2 = b0 << 1;
    b1_2 = b1 << 1;

    b1_38 = 38ULL * b1;
    b2_38 = 38ULL * b2;
    b3_38 = 38ULL * b3;

    b3_19 = 19ULL * b3;
    b4_19 = 19ULL * b4;

    a0 =   b0 * b0 + b1_38 * b4 + b2_38 * b3;
    a1 = b0_2 * b1 + b2_38 * b4 + b3_19 * b3;
    a2 = b0_2 * b2 +    b1 * b1 + b3_38 * b4;
    a3 = b0_2 * b3 +  b1_2 * b2 + b4_19 * b4;
    a4 = b0_2 * b4 +  b1_2 * b3 +    b2 * b2;

    a00    = ((uint64_t) a0) & mask;
    overflow  = (uint64_t) (a0 >> 51);
    a1    += overflow;
    a01    = ((uint64_t) a1) & mask;
    overflow  = (uint64_t) (a1 >> 51);
    a2    += overflow;
    a02    = ((uint64_t) a2) & mask;
    overflow  = (uint64_t) (a2 >> 51);
    a3    += overflow;
    a03    = ((uint64_t) a3) & mask;
    overflow  = (uint64_t) (a3 >> 51);
    a4    += overflow;
    a04    = ((uint64_t) a4) & mask;
    overflow  = (uint64_t) (a4 >> 51);
    a00   += 19ULL * overflow;
    overflow  = a00 >> 51;
    a00   &= mask;
    a01   += overflow;
    overflow  = a01 >> 51;
    a01   &= mask;
    a02   += overflow;

    h[0] = a00;
    h[1] = a01;
    h[2] = a02;
    h[3] = a03;
    h[4] = a04;
}