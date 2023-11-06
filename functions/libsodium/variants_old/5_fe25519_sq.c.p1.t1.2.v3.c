fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    g0 = f[0];
    g1 = f[1];
    g2 = f[2];
    g3 = f[3];
    g4 = f[4];

    r0 =   ((g0 * g0) + (38ULL * g1 * g4)) + (38ULL * g2 * g3) ;
    r1 =   ((g0 << 1) * g1) + (38ULL * g2 * g4) + (19ULL * g3 * g3);
    r2 =   ((g0 << 1) * g2) + ( g1 * g1) + (38ULL * g3 * g4);
    r3 =   ((g0 << 1) * g3) + ( (g1 << 1) * g2) + (19ULL * g4 * g4);
    r4 =   ((g0 << 1) * g4) + ( (g1 << 1) * g3) + (g2 * g2);

    r00 = r0 & mask;
    carry = r0 >> 51;
    r1 += carry;
    r01 = r1 & mask;
    carry = r1 >> 51;
    r2 += carry;
    r02 = r2 & mask;
    carry = r2 >> 51;
    r3 += carry;
    r03 = r3 & mask;
    carry = r3 >> 51;
    r4 += carry;
    r04 = r4 & mask;
    carry = r4 >> 51;
    r00 += 19ULL * carry;
    carry = r00 >> 51;
    r00 &= mask;
    r01 += carry;
    carry = r01 >> 51;
    r01 &= mask;
    r02 += carry;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}