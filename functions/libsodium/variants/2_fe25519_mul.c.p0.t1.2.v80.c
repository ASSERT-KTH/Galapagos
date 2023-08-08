fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t p0, p1, p2, p3, p4;
    uint128_t q0, q1, q2, q3, q4;
    uint128_t q1X19, q2X19, q3X19, q4X19;
    uint128_t r0, r1, r2, r3, r4;
    uint64_t  h00, h01, h02, h03, h04;
    uint64_t  carry;

    p0 = (uint128_t) f[0];
    p1 = (uint128_t) f[1];
    p2 = (uint128_t) f[2];
    p3 = (uint128_t) f[3];
    p4 = (uint128_t) f[4];

    r0 = (uint128_t) g[0];
    r1 = (uint128_t) g[1];
    r2 = (uint128_t) g[2];
    r3 = (uint128_t) g[3];
    r4 = (uint128_t) g[4];

    q1X19 = 19ULL * p1;
    q2X19 = 19ULL * p2;
    q3X19 = 19ULL * p3;
    q4X19 = 19ULL * p4;

    h00 = p0 * r0 + q1X19 * r4 + q2X19 * r3 + q3X19 * r2 + q4X19 * r1;
    h01 = p0 * r1 +    p1 * r0 + q2X19 * r4 + q3X19 * r3 + q4X19 * r2;
    h02 = p0 * r2 +    p1 * r1 +    p2 * r0 + q3X19 * r4 + q4X19 * r3;
    h03 = p0 * r3 +    p1 * r2 +    p2 * r1 +    p3 * r0 + q4X19 * r4;
    h04 = p0 * r4 +    p1 * r3 +    p2 * r2 +    p3 * r1 +    p4 * r0;

    p0    = ((uint64_t) h00) & mask;
    carry  = (uint64_t) (h00 >> 51);
    h01   += carry;
    p1    = ((uint64_t) h01) & mask;
    carry  = (uint64_t) (h01 >> 51);
    h02   += carry;
    p2    = ((uint64_t) h02) & mask;
    carry  = (uint64_t) (h02 >> 51);
    h03   += carry;
    p3    = ((uint64_t) h03) & mask;
    carry  = (uint64_t) (h03 >> 51);
    h04   += carry;
    p4    = ((uint64_t) h04) & mask;
    carry  = (uint64_t) (h04 >> 51);
    p0   += 19ULL * carry;
    carry  = p0 >> 51;
    p0   &= mask;
    p1   += carry;
    carry  = p1 >> 51;
    p1   &= mask;
    p2   += carry;

    h[0] = p0;
    h[1] = p1;
    h[2] = p2;
    h[3] = p3;
    h[4] = p4;
}