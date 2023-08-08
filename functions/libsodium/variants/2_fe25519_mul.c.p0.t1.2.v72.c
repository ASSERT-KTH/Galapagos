fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 8191ULL << 44;
    uint128_t r[5];
    uint128_t fVals[5];
    uint128_t multipleOf19[4];
    uint128_t gVals[5];
    uint64_t  results[5];
    uint64_t  increment;

    for (int j=0;j<5;++j)
    {
        fVals[j]=(uint128_t) f[j];
        gVals[j]=(uint128_t) g[j];
    }

    for (int i=1;i<5;++i)
    {
        multipleOf19[i-1] = 19ULL * fVals[i];
    }

    r[0] = fVals[0]*gVals[0] + multipleOf19[3]*gVals[4] + multipleOf19[2]*gVals[3] + multipleOf19[1]*gVals[2] + multipleOf19[0]*gVals[1];
    r[1] = fVals[0]*gVals[1] + fVals[1]*gVals[0] + multipleOf19[3]*gVals[4] + multipleOf19[2]*gVals[3] + multipleOf19[1]*gVals[2];
    r[2] = fVals[0]*gVals[2] + fVals[1]*gVals[1] + fVals[2]*gVals[0] + multipleOf19[3]*gVals[4] + multipleOf19[2]*gVals[3];
    r[3] = fVals[0]*gVals[3] + fVals[1]*gVals[2] + fVals[2]*gVals[1] + fVals[3]*gVals[0] + multipleOf19[3]*gVals[4];
    r[4] = fVals[0]*gVals[4] + fVals[1]*gVals[3] + fVals[2]*gVals[2] + fVals[3]*gVals[1] + fVals[4]*gVals[0];

  for (int j=0;j<4;++j)
    {
        results[j]    = ((uint64_t) r[j]) & mask;
        increment     = (uint64_t) (r[j] >> 51);
        r[j+1]       += increment;  
    }
    
    results[4]=((uint64_t) r[4]) & mask;
    increment     = (uint64_t) (r[4] >> 51);
    results[0] += 19ULL * increment;

    for (int j=0;j<2;++j)
    {
        increment = results[j] >> 51;
        results[j]= results[j] & mask;
        results[j+1] += increment;

    }

    for (int j=0;j<5;++j)
    {
        h[j] = results[j];
    }

}