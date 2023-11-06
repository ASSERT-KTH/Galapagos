void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t a0, a1, a2, a3, a4;
    uint128_t b0, b1, b2, b3, b4;
    uint128_t p0, p1, p2, p3, p4;
    uint128_t b1_19, b2_19, b3_19, b4_19;
    uint64_t  hx, hy, hz, hw, hv;
    uint64_t  carry;

    a0 = (uint128_t) f[0];
    a1 = (uint128_t) f[1];
    a2 = (uint128_t) f[2];
    a3 = (uint128_t) f[3];
    a4 = (uint128_t) f[4];

    b0 = (uint128_t) g[0];
    b1 = (uint128_t) g[1];
    b2 = (uint128_t) g[2];
    b3 = (uint128_t) g[3];
    b4 = (uint128_t) g[4];

    b1_19 = 19ULL * b1;
    b2_19 = 19ULL * b2;
    b3_19 = 19ULL * b3;
    b4_19 = 19ULL * b4;

    p0 = a0 * b0 + a1 * b4_19 + a2 * b3_19 + a3 * b2_19 + a4 * b1_19;
    p1 = a0 * b1 + a1 * b0 + a2 * b4_19 + a3 * b3_19 + a4 * b2_19;
    p2 = a0 * b2 + a1 * b1 + a2 * b0 + a3 * b4_19 + a4 * b3_19;
    p3 = a0 * b3 + a1 * b2 + a2 * b1 + a3 * b0 + a4 * b4_19;
    p4 = a0 * b4 + a1 * b3 + a2 * b2 + a3 * b1 + a4 * b0;

    hx = ((uint64_t) p0) & mask; 
    carry = (uint64_t) (p0 >> 51); 
    p1 += carry;
    hy = ((uint64_t) p1) & mask;
    carry = (uint64_t) (p1 >> 51) ;
    p2 += carry; 
    hz = ((uint64_t) p2) & mask; 
    carry = (uint64_t) (p2 >> 51);
    p3 += carry;
    hw = ((uint64_t) p3) & mask;
    carry  = (uint64_t) (p3 >> 51); 
    p4 += carry;
    hv = ((uint64_t)p4) & mask;
    carry = (uint64_t)(p4 >> 51);
    hx += 19ULL * carry;
    carry = hx >> 51;
    hx &= mask;
    hy += carry;
    carry = hy >> 51;
    hy &= mask;
    hz += carry;
    
    h[0] = hx;
    h[1] = hy;
    h[2] = hz;
    h[3] = hw;
    h[4] = hv;
}