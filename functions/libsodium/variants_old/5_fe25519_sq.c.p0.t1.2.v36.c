fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t h0_h3, h0_h2, h0_h4;
    uint64_t  h1_h4, h2_h3;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    /* rearrange */
    f0 = (uint128_t) f[2];
    f1 = (uint128_t) f[3];
    f2 = (uint128_t) f[4];
    f3 = (uint128_t) f[0];
    f4 = (uint128_t) f[1];  

    h0_h3 = 2 * f0;
    h0_h2 = 2 * f1;
    h1_h4 = 38 * f2; /* 1.4*2^37 */
    h2_h3 = 38 * f4; /* 1.4*2^39 */
    h0_h4 = 19 * f3; /* 1.9*2^40 */

    r0 = f4*f4 + h1_h4*f3 + h2_h3*f2;
    r1 = h0_h4*f1 + h1_h4*f2*f4 + f3*f3;
    r2 = h0_h3*f2 + f1*f1 + h1_h4*f4;
    r3 = h0_h3*f3 + h0_h2*f2 + f0*f0;
    r4 = h0_h3*f4 + h0_h2*f3 + h2_h3*f1;

    r00    = ((uint64_t) r0) & mask;
    carry  = (uint64_t) (r0 >> 51);
    r1    += carry;
    r01    = ((uint64_t) r1) & mask;
    carry  = (uint64_t) (r1 >> 51);
    r2    += carry;
    r02    = ((uint64_t) r2) & mask;
    carry  = (uint64_t) (r2 >> 51);
    r3    += carry;
    r03    = ((uint64_t) r3) & mask;
    carry  = (uint64_t) (r3 >> 51);
    r4    += carry;
    r04    = ((uint64_t) r4) & mask;
    carry  = (uint64_t) (r4 >> 51);
    r00   += 19ULL * carry;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    r02   += carry;

    h[0] = r01;
    h[1] = r02;
    h[2] = r03;
    h[3] = r04;
    h[4] = r00;
}