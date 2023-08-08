fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], fi_top[5];
    uint64_t  carry, r_res[5];

    for (int i = 0; i < 5; ++i) 
    {
        r[i] = 0;
        fi_top[i] = (i == 1 || i == 2 || i == 3 || i == 4) ? 19 * (uint128_t)f[i] : (uint128_t)f[i];
    }

    for (int j = 0; j < 5; ++j) 
    {
        for (int i = 0; i < 5; ++i) 
        {
            r[(i+j)%5] += ((uint128_t)f[((i+j)%5+i)%5] * (uint128_t)g[((i+j)%5+i)%5*j%5]) +  
                           ((i!=0 && (i+j)%5+i!=0) ? 0ULL :fi_top[(i+j)%5+i]*g[(5-j+i)%5]);
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        r_res[i] = (uint64_t)r[i]&mask;
        carry = (uint64_t)(r[i]>>51);
        if((i+1)<5)
            r[i+1] += carry;
        else
            r_res[i % 5] += 19ULL * carry;
    }

    for (int i = 0; i < 5; ++i)
    {
        if(r_res[i] > mask) 
        {
            if((i+1)<5)
                r_res[i+1] += r_res[i] >> 51;
            else
                r_res[i % 5] += 19ULL * (r_res[i] >> 51);
            r_res[i] &= mask;
        }
    }

    for (int i = 0; i < 5; i++)
        h[i] = r_res[i];
}