
fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t multiply[5];
    uint64_t g_values[5], carry, r_values[5];
    
    for(int i=0; i<5; i++)
    {
        multiply[i] = (uint128_t) f[i];
        g_values[i] = (uint128_t) g[i];
    }

    for(int i=1; i<5; i++)
        multiply[i]*=19ULL;
    
    for(int i=0; i<5; i++)
    {
        r[i] = multiply[0]*g_values[i];
        int k =4;
        for(int j=i; j<(5+i); j++)
        {
            int index = (j+1)%5;
            if (i != 0)
                r[i] += (i>k) ? multiply[i-k]*g_values[k--]: (uint128_t)f[i-k]*g_values[k--];
            else
                r[i] += multiply[4-j]*g_values[index];
        }
    }

    uint64_t carrySum;
    carry = 0;
    for(int k=0;k<5;k++)
    {

        r_values[k] = r[k] + carry;
        carrySum = (r_values[k] >> 51);
        carry = carrySum;
        r_values[k] = r_values[k] & mask;
        if(k<5) carrySum= 0;
    }
     for(int i=0; i<2; i++)
    {
        carrySum = (i>0) ? r_values[i-1] >> 51 : 19ULL*carrySum  ;
        r_values[i] &= mask;
        r_values[i+1] += carrySum;
    }

    for(int i=0; i<5; i++) h[i] = r_values[i];
}
