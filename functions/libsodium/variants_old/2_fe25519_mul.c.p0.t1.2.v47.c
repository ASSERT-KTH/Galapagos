fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t a0, a1, a2, a3, a4;
    uint128_t b0, b1, b2, b3, b4;
    uint128_t x19, y19, z19, w19;
    uint128_t p0, q0, r0, s0, t0;
    uint64_t  a00, a01, a02, a03, a04;
    uint64_t  overflow;

    b0 = (uint128_t) f[0];
    b1 = (uint128_t) f[1];
    b2 = (uint128_t) f[2];
    b3 = (uint128_t) f[3];
    b4 = (uint128_t) f[4];

    p0 = (uint128_t) g[0];
    q0 = (uint128_t) g[1];
    r0 = (uint128_t) g[2];
    s0 = (uint128_t) g[3];
    t0 = (uint128_t) g[4];

    x19 = 19ULL * b1;
    y19 = 19ULL * b2;
    z19 = 19ULL * b3;
    w19 = 19ULL * b4;

    a0 = b0 * p0 + x19 * t0 + y19 * s0 + z19 * r0 + w19 * q0;
    a1 = b0 * q0 +  b1 * p0 + y19 * t0 + z19 * s0 + w19 * r0;
    a2 = b0 * r0 +  b1 * q0 +  b2 * p0 + z19 * t0 + w19 * s0;
    a3 = b0 * s0 +  b1 * r0 +  b2 * q0 +  b3 * p0 + w19 * t0;
    a4 = b0 * t0 +  b1 * s0 +  b2 * r0 +  b3 * q0 +  b4 * p0;

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