variant 1:

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;
    uint128_t g0 = (uint128_t) g[0], g1 = (uint128_t) g[1], g2 = (uint128_t) g[2], g3 = (uint128_t) g[3], g4 = (uint128_t) g[4];
    uint128_t r0 = ((uint128_t) f[0]) * g0 + 19ULL * ((uint128_t) f[1]) * g4 + 19ULL * ((uint128_t) f[2]) * g3 + 19ULL * ((uint128_t) f[3]) * g2 + 19ULL * ((uint128_t) f[4]) * g1;
    uint128_t r1 = ((uint128_t) f[0]) * g1 + ((uint128_t)f[1]) * g0 + 19ULL * ((uint128_t) f[2]) * g4 + 19ULL * ((uint128_t) f[3]) * g3 + 19ULL * ((uint128_t) f[4]) * g2;
    uint128_t r2 = ((uint128_t) f[0]) * g2 + ((uint128_t)f[1]) * g1 + ((uint128_t)f[2])* g0 + 19ULL * ((uint128_t) f[3]) * g4 + 19ULL * ((uint128_t) f[4]) * g3;
    uint128_t r3 = ((uint128_t) f[0]) * g3 + ((uint128_t)f[1]) * g2 + ((uint128_t)f[2])* g1 + ((uint128_t)f[3])* g0 + 19ULL * ((uint128_t) f[4]) * g4;
    uint128_t r4 = ((uint128_t) f[0]) * g4 + ((uint128_t)f[1]) * g3 + ((uint128_t)f[2])* g2 + ((uint128_t)f[3])* g1 + ((uint128_t)f[4])* g0;
    const uint64_t mask = 0x7ffffffffffffULL;

    r00    = ((uint64_t) r0) & mask;
    carry  = (uint64_t) (r0 >> 51);
    r1    += carry;
    r01    = ((uint64_t) r1) & mask;
    carry  = (uint64_t) (r1 >> 51);
    r2    += carry;
    r02    = ((uint64_t) r2) & mask;
    carry  = (uint64_t) (r2 >> 51);
    r3    += carry;
    r03    = ((uint64_t) r3) & mask;
    carry  = (uint64_t) (r3 >> 51);
    r4    += carry;
    r04    = ((uint64_t) r4) & mask;
    carry  = (uint64_t) (r4 >> 51);
    r00   += 19ULL * carry;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    r02   += carry;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}

variant 2:

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    const uint128_t fVals[5] = {(uint128_t) f[0],(uint128_t) f[1],(uint128_t) f[2],(uint128_t) f[3],(uint128_t) f[4]};
    const uint128_t gVals[5] = {(uint128_t) g[0],(uint128_t) g[1],(uint128_t) g[2],(uint128_t) g[3],(uint128_t) g[4]};
    uint128_t rVals[5];
    uint64_t  rVals64[5];
    uint64_t  carry;

    for(uint8_t i = 0; i < sizeof(rVals)/sizeof(rVals[0]); i++)
    {
        rVals[i] = fVals[0] * gVals[(5-i)%5];
        
        for(uint8_t j = 1; j < sizeof(fVals)/sizeof(fVals[0]); j++)
        rVals[i] += ( (i-j) % 5 == 0 ? fVals[j] : 19ULL * fVals[j]) * gVals[(5-i-j)%5]

        if(i !=0)
        {
            rVals64[(i-1)%5] = ((uint64_t) rVals[(i-1)%5]) & mask;
            carry  = (uint64_t) (rVals[(i-1)%5] >> 51);
            rVals[i%5]    += carry;
        }
    }

    /* Last Iteration for i=5 */
    rVals64[4] = ((uint64_t) rVals[4]) & mask;
    carry  = (uint64_t) (rVals[4] >> 51);
    rVals64[0] += 19ULL*carry;
    carry = rVals64[0] >> 51;
    rVals64[0] &= mask;
    rVals64[1] += carry;
    carry = rVals64[1] >> 51;
    rVals64[1] &= mask;
    rVals64[2] += carry;

    memcpy(h,rVals64,sizeof h);
}
