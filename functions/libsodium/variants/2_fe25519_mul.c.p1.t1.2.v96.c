void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask =  0x7ffffffffffffULL;
    uint128_t      t[10];
    uint64_t       c, r[5];

    for(int i=0; i<5; i++){
        t[i]   = i<4 ? 19ULL * ((uint128_t)f[i+1]) * ((uint128_t)g[4-i]) : 0;
        t[i+5] =  ((uint128_t)f[i])  * ((uint128_t)g[0]);
    }

    for(int i=0; i<5; i++)
        for(int j=1; j<=4-i; j++)
            t[i+j+5] = ((uint128_t)f[i+j]) * ((uint128_t)g[j]);

    t[0]   += t[5] + t[6] + t[7] + t[8];
    t[1]   += t[6] + t[7] + t[8] + t[9];
    t[2]   += t[7] + t[8] + t[9];
    t[3]   += t[8] + t[9];
    t[4]   += t[9];

    r[0]  = (uint64_t)(t[0]) & mask;
    c     = (uint64_t)(t[0] >> 51);
    t[1] += c;
    r[1]  = (uint64_t)(t[1]) & mask;
    c     = (uint64_t)(t[1] >> 51);
    t[2] += c;
    r[2]  = (uint64_t)(t[2]) & mask;
    c     = (uint64_t)(t[2] >> 51);
    t[3] += c;
    r[3]  = (uint64_t)(t[3]) & mask;
    c     = (uint64_t)(t[3] >> 51);
    t[4] += c;
    r[4]  = (uint64_t)(t[4]) & mask;
    c     = (uint64_t)(t[4] >> 51);
    r[0] += 19ULL * c;
    c     = r[0] >> 51;
    r[0] &= mask;
    r[1] += c;
    c     = r[1] >> 51;
    r[1] &= mask;
    r[2] += c;

    for(int i=0; i<5; i++)
        h[i] = r[i];
}