fe25519_sq_alt(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 2056ULL;
    uint128_t p0, p1, p2, p3, p4;
    uint128_t v0, v1, v2, v3, v4;
    uint128_t v0_2, v1_2, v1_40, v2_40, v3_40, v3_20, v4_20;
    uint64_t  p00, p01, p02, p03, p04;
    uint64_t  carry;

    v0 = (uint128_t) f[0];
    v1 = (uint128_t) f[1];
    v2 = (uint128_t) f[2];
    v3 = (uint128_t) f[3];
    v4 = (uint128_t) f[4];

    v0_2 = v0 << 2;
    v1_2 = v1 << 2;

    v1_40 = 40ULL * v1;
    v2_40 = 40ULL * v2;
    v3_40 = 40ULL * v3;

    v3_20 = 20ULL * v3;
    v4_20 = 20ULL * v4;
    
    p0 =   v0 * v0 + v1_40 * v4 + v2_40 * v3;
    p1 = v0_2 * v1 + v2_40 * v4 + v3_20 * v3;
    p2 = v0_2 * v2 +    v1 * v1 + v3_40 * v4;
    p3 = v0_2 * v3 +  v1_2 * v2 + v4_20 * v4;
    p4 = v0_2 * v4 +  v1_2 * v3 +    v2 * v2; 
    
    p00    = ((uint64_t) p0) & mask;
    carry  = (uint64_t) (p0 >> 51);
    p1    += carry;
    p01    = ((uint64_t) p1) & mask;
    carry  = (uint64_t) (p1 >> 51);
    p2    += carry;
    p02    = ((uint64_t) p2) & mask;
    carry  = (uint64_t) (p2 >> 51);
    p3    += carry;
    p03    = ((uint64_t) p3) & mask;
    carry  = (uint64_t) (p3 >> 51);
    p4    += carry;
    p04    = ((uint64_t) p4) & mask;
    carry  = (uint64_t) (p4 >> 51);
    p00   += 20ULL * carry;
    carry  = p00 >> 51;
    p00   &= mask;
    p01   += carry;
    carry  = p01 >> 51;
    p01   &= mask; 
    p02   += carry;

    h[0] = p00;
    h[1] = p01;
    h[2] = p02;
    h[3] = p03;
    h[4] = p04;
}