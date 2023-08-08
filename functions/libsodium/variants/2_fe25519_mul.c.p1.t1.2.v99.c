fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t results[5];
    uint128_t fvalues[5], gvalues[5];
    uint128_t scaled_list[4];
    uint64_t carries[4];
    uint64_t maskVals[5];

    for (int i = 0; i < 5; i++)
    {
        fvalues[i] = (uint128_t) f[i];
        gvalues[i] = (uint128_t) g[i];
        results[i] = 0;
    }

    for (int i = 1; i < 5; i++)
    {
        scaled_list[i - 1] = 19ULL * fvalues[i];
    }

    results[0] =  fvalues[0]*gvalues[0] + scaled_list[0]*gvalues[4] + scaled_list[1]*gvalues[3] + scaled_list[2]*gvalues[2] + 
scaled_list[3]*gvalues[1];
    for (int i = 1; i < 5; i++)
    {
        results[i] =  fvalues[0]*gvalues[i] + fvalues[1]*gvalues[i - 1] + fvalues[i]*gvalues[0];
        if (i < 4)
        {
            results[i] += scaled_list[i]*gvalues[4 - i] + scaled_list[i - 1]*gvalues[3 - i];
        }
    }

    for(int i = 0; i < 5; ++i)
    {
        maskVals[i] = (uint64_t) results[i] & mask;
        carries[i] = (uint64_t) (results[i] >> 51);
        if (i < 4)
        {
            results[i + 1] += carries[i];
        }
    }

    maskVals[0] += 19ULL * carries[4]; 
    maskVals[0]  &= mask;

    for (int i = 1; i < 5; i++)
    {
        maskVals[i] += (maskVals[i - 1] >> 51);
        maskVals[i] &= mask;
    }

    for (int i = 0; i < 5; i++)
    {
        h[i] = maskVals[i];
    }
}