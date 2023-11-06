void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g0, g1, g2, g3, g4;
    uint128_t t[5];
    uint64_t carry;
    int i,j;

    g0 = (uint128_t) g[0];
    g1 = (uint128_t) g[1];
    g2 = (uint128_t) g[2];
    g3 = (uint128_t) g[3];
    g4 = (uint128_t) g[4];

    f1_19 = 19ULL * f[1];
    f2_19 = 19ULL * f[2];
    f3_19 = 19ULL * f[3];
    f4_19 = 19ULL * f[4];

    for(i=0; i<5; i++)
    { 
        t[i] = ((uint128_t) f[i]) * g0 + f1_19 *   *((g + 4 - i) % 5) + f2_19 *  *((g + 3 - i) % 5) +
                 f3_19 *  *((g + 2 - i) % 5) + f4_19 *   *((g + 1 - i) % 5);

        carry = ((uint64_t) t[i]) >> 51;
        t[i] = ((uint64_t) t[i]) & mask;

        if (i != 0){
            for(j=i-1; j>0; j--){
            carry = (t[j] + carry) >> 51;
            t[j] = (t[j] + carry) & mask;
            }
            t[0] += 19ULL * carry;
        }
    }
    
    for(i=0; i<5; i++){
        carry = t[i] >> 51;
        t[i] &= mask;
        t[(i+1)%5] += carry;
    }
    
    for(i=0; i<5; i++){
        h[i] = t[i];
    }
}