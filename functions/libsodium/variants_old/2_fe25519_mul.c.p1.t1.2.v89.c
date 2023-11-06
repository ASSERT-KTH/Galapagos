fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint64_t mask = 0x7ffffffffffffULL;
    uint128_t w[5];
    uint64_t g1_19, g12_38_19, r[5], carry;
    
    g1_19 = 19ULL * g[1]; 

    w[0] = ((uint128_t)f[0] * g[0]) + ((uint128_t)f[1] * g[4] * (uint128_t)19ULL) + ((uint128_t)f[2] * g[3] * (uint128_t)19ULL) + ((uint128_t)f[3] * g[2] * (uint128_t)19ULL)                      + ((uint128_t)f[4] * g[1] * (uint128_t)19ULL);
    w[1] = ((uint128_t)f[0] * g[1]) + ((uint128_t)f[1] * g[0]) + ((uint128_t)f[2] * g[4] * (uint128_t)19ULL) + ((uint128_t)f[3] * g[3] * (uint128_t)19ULL)                      + ((uint128_t)f[4] * g[2] * (uint128_t)19ULL);
    w[2] = ((uint128_t)f[0] * g[2]) + ((uint128_t)f[1] * g[1]) + ((uint128_t)f[2] * g[0]) + ((uint128_t)f[3] * g[4] * (uint128_t)19ULL)                                     + ((uint128_t)f[4] * g[3] * (uint128_t)19ULL);
    w[3] = ((uint128_t)f[0] * g[3]) + ((uint128_t)f[1] * g[2]) + ((uint128_t)f[2] * g[1]) + ((uint128_t)f[3] * g[0]) + ((uint128_t)f[4] * g[4] * (uint128_t)19ULL);
    w[4] = ((uint128_t)f[0] * g[4]) + ((uint128_t)f[1] * g[3]) + ((uint128_t)f[2] * g[2]) + ((uint128_t)f[3] * g[1]) + ((uint128_t)f[4] * g[0]);
    
    r[0] = (uint64_t) w[0] &  mask;
    carry =  w[0] >> 51;
    w[1] += carry;
    r[1] = (uint64_t)w[1] & mask;
    carry = w[1] >>51;
    w[2] += carry;
    r[2] = (uint64_t)w[2] & mask;
    carry = w[2] >>51;
    w[3] += carry;
    r[3] = (uint64_t)w[3] & mask;
    carry = w[3] >> 51;
    w[4] += carry;

    r[4] = (uint64_t)w[4] & mask;
    carry = w[4] >> 51;
    r[0] = r[0] + carry * (uint64_t)19ULL;
    carry = r[0] >> 51;
    r[0] = r[0] & mask;
    r[1] += carry;
    carry = r[1] >> 51;
    r[1] = r[1] & mask;
    r[2] += carry;

    for(int i = 0; i<5; i++)
        h[i] = r[i];	
}