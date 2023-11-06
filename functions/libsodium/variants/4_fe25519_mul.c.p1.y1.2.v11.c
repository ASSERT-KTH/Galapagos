Variant 1:

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t fr[5], gr[5], f12[4], f0, f1, f2, r[5];
    uint64_t  carry, result[5];
    
    for(int i = 0; i < 5; i++)
    {
        fr[i] = (uint128_t) f[i];
        gr[i] = (uint128_t) g[i];
    }  

    for(int i = 1; i < 5; i++)
        f12[i-1] = 19ULL * fr[i];
        
    f0 = fr[0];
    f1 = fr[1];
    f2 = fr[2];
    
    r[0] = f0 * gr[0] + f12[3] * gr[3] + f12[2] * gr[2] + f12[1] * gr[1] + f12[0] * gr[0];
    r[1] = f0 * gr[1] +    f1 * gr[0] + f12[0] * gr[3] + f12[1] * gr[2] + f12[2] * gr[1];
    r[2] = f0 * gr[2] +    f1 * gr[1] +    f2 * gr[0] + f12[1] * gr[3] + f12[0] * gr[2];
    r[3] = f0 * gr[3] +    f1 * gr[2] +    f2 * gr[1] +    fr[3] * gr[0] + f12[0] * gr[3];
    r[4] = f0 * gr[4] +    f1 * gr[3] +    f2 * gr[2] +    fr[3] * gr[1] +    fr[4] * gr[0];
    
    for(int i = 0; i < 5; i++)
    {
        result[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1] += carry; 
    }

    result[0] += 19ULL * carry;
    carry  = result[0] >> 51;
    result[0] &= mask;
    result[1] += carry;

    for(int i = 0; i < 5; i++)
        h[i] = result[i];
}


Variant 2:

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    ...
    //combining f-value assignments
    f0 = (uint128_t) f[0], f1 = (uint128_t) f[1], f2 = (uint128_t) f[2], f3 = (uint128_t) f[3], f4 = (uint128_t) f[4];

    //combining g-value assignments
    g0 = (uint128_t) g[0], g1 = (uint128_t) g[1], g2 = (uint128_t) g[2], g3 = (uint128_t) g[3], g4 = (uint128_t) g[4];

    //combining xi_19 and r assignments and simplifying expressions
    r0 = f0 * g0 + 19ULL * (f1 * g4 + f2 * g3 + f3 * g2 + f4 * g1);
    r1 = f0 * g1 + f1      * g0 + 19ULL * (f2 * g4 + f3_19 * g3 + f4_19 * g2);
    r2 = f0 * g2 + f1      * g1 + f2     * g0 + 19ULL * (f3 * g4 + f4   * g3);
    ...
}