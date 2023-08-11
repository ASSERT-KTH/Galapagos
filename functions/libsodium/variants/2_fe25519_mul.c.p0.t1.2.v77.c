fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f1_2, f2_2, f3_2, f4_2;
    uint64_t g0, g1, g2, g3, g4;
    uint64_t h0, h1, h2, h3, h4;
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    g0 = (uint64_t) g[0];
    g1 = (uint64_t) g[1];
    g2 = (uint64_t) g[2];
    g3 = (uint64_t) g[3];
    g4 = (uint64_t) g[4];

    f1_2 = 2 * f1;
    f2_2 = 2 * f2;
    f3_2 = 2 * f3;
    f4_2 = 2 * f4;

    r0 = f0*g0 + f1_2*g4 + f2_2*g3 + f3_2*g2 + f4_2*g1;
    r1 = f0*g1 + f1*g0 + f3_2*g4 + f2_2*g3 + f4_2*g2;
    r2 = f0*g2 + f2*g0 + f1*g1 + f4_2*g4 + f3_2*g3;
    r3 = f0*g3 + f3*g0 + f4*g2 + f1*g1 + f3_2*g4;
    r4 = f0*g4 + f4*g0 + f3*g3 + f2*g2 + f1*g1;

    h0 = r0 & mask;
    carry = r0 >> 51;
    r1 += carry;
    h1 = r1 & mask;
    carry = r1 >> 51;
    r2 += carry; 
    h2 = r2 & mask; 
    carry = r2 >> 51;
    r3 += carry; 
    h3 = r3 & mask; 
    carry  = r3 >> 51; 
    r4    += carry; 
     
    h4 = r4 & mask; 

    carry  = r4 >> 51;
    h0    += 19ULL * carry;
    carry   = h0 >> 51; 
    h0    &= mask;
    
    h1    += carry;
    carry = r1 >> 51;
    h1   &= mask;
    
    h2 += carry; 
     

    h[0] = h0;
    h[1] = h1;
    h[2] = h2;
    h[3] = h3;
    h[4] = h4;
}