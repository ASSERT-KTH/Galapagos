fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g0, g1, g2, g3, g4;
    
    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    g0 = (uint128_t) g[0];
    g1 = (uint128_t) g[1];
    g2 = (uint128_t) g[2];
    g3 = (uint128_t) g[3];
    g4 = (uint128_t) g[4];

    f1_19 = 19ULL * f1;
    f2_19 = 19ULL * f2;
    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    r0 = g0 * f0 + g4 * f1_19 + g3 * f2_19 + g2 * f3_19 + g1 * f4_19;
    r1 = g1 * f0 + g0 * f1 + g4 * f2_19 + g3 * f3_19 + g2 * f4_19;
    r2 = g2 * f0 + g1 * f1 + g0 * f2 + g4 * f3_19 + g3 * f4_19;
    r3 = g3 * f0 + g2 * f1 + g1 * f2 + g0 * f3 + g4 * f4_19;
    r4 = g4 * f0 + g3 * f1 + g2 * f2 + g1 * f3 + g0 * f4;

    for (int i = 0; i<5; i++){
        static uint64_t carry;
        r[c]   += carry;
        static uint_64 ti; 
        ti      = r[c] & mask;;
        carry   = r[c] >> 51;
        h[c]    = ti;
    }

    for(int i=0; i<50; i++){
        static uint64_t carry;
        static uint_64 ti, cj;
        cj  += 19ULL * h[0];
        ti  = cj & mask;
        carry = cj >> 51;;
        h[c]+= carry;;
    }
}