void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f0, f1, f2, f3, f4, g0, g1, g2, g3, g4;
    uint128_t sub_result0, sub_result1,sub_result2,sub_result3,sub_result4;
    uint128_t r[5];
    uint64_t carry;
    
    for(int i = 0; i <5 ;i++)
    {
        f[i] = (uint128_t) f[i];
        g[i] = (uint128_t) g[i];
    }

    uint128_t products[5][5]={ {f[0] * g[0], f[0] * g[1], f[0] * g[2], f[0] * g[3], f[0] * g[4]},
                                {f[1] * g[0],19ULL * f[1] * g[4], f[1] * g[1], 19ULL * f[1] * g[3],19ULL * f[1] *g[2]},
                                {f[2] * g[0], f[2] * g[1],19ULL * f[2] * g[4], f[2] * g[2],19ULL * f[2] *g[3]},
                                {f[3] * g[0], f[3] * g[1], f[3] * g[2],19ULL * f[3] * g[4], f[3] *g[3]},
                                {f[4] * g[0], f[4] * g[1], f[4] * g[2], f[4] * g[3], 19ULL * f[4]*g[4]}};

    for(int i=0;i<5;i++)
    {  
        r[i]=0;
        for(int j=0;j<5;j++)
            r[i]+= products[j][(i+j)%5];
    }

    for(int i=0;i<5;i++)
    {
        h[i] = (uint64_t) (r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        r[(i+1)%5] += carry;
        
        if(i==4)
        {
            h[0] += 19ULL * carry;
            carry = (h[0] >> 51);
        }
        else
        {
            carry = (uint64_t) (r[(i+1)%5] >> 51);
        }

        h[i] &= mask;
        h[(i + 1) % 5] += carry;
    }
}