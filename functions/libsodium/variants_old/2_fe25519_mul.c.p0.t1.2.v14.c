fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t r[5], carry;
    
    for (int index=0; index <5 ; ++index) {
        f0 = (uint128_t) f[index];
        g0 = (uint128_t) g[index];

        f1_19 = 19ULL * f0;
        r[index] = f0 * g0 + f1_19 * g[4-index] + f2_19 * g[4-index-1>0?4-index-1:0] 
                       + f3_19 * g[4-index-2>0?4-index-2:0] + f4_19 * g[3-index>0?3-index:0];
                       
        r[index] = ((uint64_t) r[index]) & mask;
        carry  = (uint64_t) (r[index] >> 51);
        r[index+1] += carry;
        r[index] = ((uint64_t) r[index+1]) & mask;
        carry  = (uint64_t) (r[index+1] >> 51);
        
        r[0] += 19ULL * carry;
        carry  = r[0] >> 51;
        r[0] &= mask;
        r[1] += carry;
        carry  = r[1] >> 51;
        r[1] &= mask;
        r[2] += carry;

        h[index] = r[index];
      }
}