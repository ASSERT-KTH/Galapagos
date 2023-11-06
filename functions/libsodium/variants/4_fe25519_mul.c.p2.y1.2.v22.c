void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    static const uint64_t mask =0x7ffffffffffffULL;
    const uint64_t f0 = (uint64_t) f[0];
    const uint64_t f1 = (uint64_t) f[1];
    const uint64_t f2 = (uint64_t) f[2];
    const uint64_t f3 = (uint64_t) f[3];
    const uint64_t f4 = (uint64_t) f[4];

    const uint64_t g0 = (uint64_t) g[0];
    const uint64_t g1 = (uint64_t) g[1];
    const uint64_t g2 = (uint64_t) g[2];
    const uint64_t g3 = (uint64_t) g[3];
    const uint64_t g4 = (uint64_t) g[4];

    const uint64_t f1_19 = 19ULL * f1;
    const uint64_t f2_19 = 19ULL * f2;
    const uint64_t f3_19 = 19ULL * f3;
    const uint64_t f4_19 = 19ULL * f4;

    uint128_t r[5]; 

    r[0] = f0 * g0 + f1_19 * g4 + f2_19 * g3 + f3_19 * g2 + f4_19 * g1;
    r[1] = f0 * g1 + f1 * g0 + f2_19 * g4 + f3_19 * g3 + f4_19 * g2;
    r[2] = f0 * g2 + f1 * g1 + f2 * g0 + f3_19 * g4 + f4_19 * g3;
    r[3] = f0 * g3 + f1 * g2 + f2 * g1 + f3 * g0 + f4_19 * g4;
    r[4] = f0 * g4 + f1 * g3 + f2 * g2 + f3 * g1 + f4 * g0;


    uint64_t carry;
    for (uint8_t i = 0; i < 4; i++){
        h[i] = ((uint64_t)r[i]) & mask;
        carry = r[i] >> 51;
        r[i+1] += carry;
    }
    h[4] = r[4] & mask; 

    uint64_t t = h[0] + (r[4] >> 51) * 19;  
    h[0] = t & mask;
    
    t = h[1] + (t >> 51);
    h[1] = t & mask;
    
    t = h[2] + (t >> 51);
    h[2] = t & mask;

    t = h[3] + (t >> 51);
    h[3] = t & mask;
    
    h[4] += t >> 51;
}