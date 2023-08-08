fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint64_t const mask = 0x7ffffffffffffULL;
    uint128_t r[5], f0, f1, f2, f3, f4;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g[5];
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    g[0] = (uint128_t) g[0];
    g[1] = (uint128_t) g[1];
    g[2] = (uint128_t) g[2];
    g[3] = (uint128_t) g[3];
    g[4] = (uint128_t) g[4];

    f1_19 = 19ULL * f1;
    f2_19 = 19ULL * f2;
    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    r[0] = f0 * g[0] + f1_19 * g[4] + f2_19 * g[3] + f3_19 * g[2] + f4_19 * g[1];
    r[1] = f0 * g[1] +    f1 * g[0] + f2_19 * g[4] + f3_19 * g[3] + f4_19 * g[2];
    r[2] = f0 * g[2] +    f1 * g[1] +    f2 * g[0] + f3_19 * g[4] + f4_19 * g[3];
    r[3] = f0 * g[3] +    f1 * g[2] +    f2 * g[1] +    f3 * g[0] + f4_19 * g[4];
    r[4] = f0 * g[4] +    f1 * g[3] +    f2 * g[2] +    f3 * g[1] +    f4 * g[0];

    for(int i = 0; i < 5; i++){
        h[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        if(i != 4) r[i+1] += carry;
        if(i == 4) h[0] += 19ULL * carry;
    }

    carry = h[0] >> 51; 
    h[0] = h[0] & mask; 
    h[1] = h[1] + carry;

}
