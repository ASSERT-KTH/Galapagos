fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t rv0, rv1, rv2, rv3, rv4;
    uint128_t fv0, fv1, fv2, fv3, fv4;
    uint128_t fv1_19, fv2_19, fv3_19, fv4_19;
    uint128_t gv0, gv1, gv2, gv3, gv4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    fv0 = (uint128_t) f[0];
    fv1 = (uint128_t) f[1];
    fv2 = (uint128_t) f[2];
    fv3 = (uint128_t) f[3];
    fv4 = (uint128_t) f[4];

    gv0 = (uint128_t) g[0];
    gv1 = (uint128_t) g[1];
    gv2 = (uint128_t) g[2];
    gv3 = (uint128_t) g[3];
    gv4 = (uint128_t) g[4];

    fv1_19 = 19ULL * fv1;
    fv2_19 = 19ULL * fv2;
    fv3_19 = 19ULL * fv3;
    fv4_19 = 19ULL * fv4;

    rv0 = fv0 * gv0 + fv1_19 * gv4 + fv2_19 * gv3 + fv3_19 * gv2 + fv4_19 * gv1;
    rv1 = fv0 * gv1 +    fv1 * gv0 + fv2_19 * gv4 + fv3_19 * gv3 + fv4_19 * gv2;
    rv2 = fv0 * gv2 +    fv1 * gv1 +    fv2 * gv0 + fv3_19 * gv4 + fv4_19 * gv3;
    rv3 = fv0 * gv3 +    fv1 * gv2 +    fv2 * gv1 +    fv3 * gv0 + fv4_19 * gv4;
    rv4 = fv0 * gv4 +    fv1 * gv3 +    fv2 * gv2 +    fv3 * gv1 +    fv4 * gv0;

    r00    = ((uint64_t) rv0) & mask;
    carry  = (uint64_t) (rv0 >> 51);
    rv1    += carry;
    r01    = ((uint64_t) rv1) & mask;
    carry  = (uint64_t) (rv1 >> 51);
    rv2    += carry;
    r02    = ((uint64_t) rv2) & mask;
    carry  = (uint64_t) (rv2 >> 51);
    rv3    += carry;
    r03    = ((uint64_t) rv3) & mask;
    carry  = (uint64_t) (rv3 >> 51);
    rv4    += carry;
    r04    = ((uint64_t) rv4) & mask;
    carry  = (uint64_t) (rv4 >> 51);
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