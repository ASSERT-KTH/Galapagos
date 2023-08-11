fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t a, b, c, d, e;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    f0_2 = f0 << 1;
    f1_2 = f1 << 1;

    f1_38 = 38ULL * f1;
    f2_38 = 38ULL * f2;
    f3_38 = 38ULL * f3;

    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    a =   f0 * f0 + f1_38 * f4 + f2_38 * f3;
    b = f0_2 * f1 + f2_38 * f4 + f3_19 * f3;
    c = f0_2 * f2 +    f1 * f1 + f3_38 * f4;
    d = f0_2 * f3 +  f1_2 * f2 + f4_19 * f4;
    e = f0_2 * f4 +  f1_2 * f3 +    f2 * f2;

    r00    = ((uint64_t) a) & mask;
    carry  = (uint64_t) (a >> 51);
    b     += carry;
    r01    = ((uint64_t) b) & mask;
    carry  = (uint64_t) (b >> 51);
    c     += carry;
    r02    = ((uint64_t) c) & mask;
    carry  = (uint64_t) (c >> 51);
    d     += carry;
    r03    = ((uint64_t) d) & mask;
    carry  = (uint64_t) (d >> 51);
    e     += carry;
    r04    = ((uint64_t) e) & mask;
    carry  = (uint64_t) (e >> 51);
    r00   += 19ULL * carry;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    r02   += carry;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}