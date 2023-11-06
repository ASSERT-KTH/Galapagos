fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5] = {0};
    uint128_t f_coeff[5] = {0};
    uint128_t g_coeff[5] = {0};
    uint64_t  carry;

    for (int i = 0; i < 5; i++)
    {
        f_coeff[i] = (uint128_t) f[i];
        g_coeff[i] = (uint128_t) g[i];
    }

    for (int i = 0;i<5;i++)
    {
        r[i] = f_coeff[0] * g_coeff[(0+i)%5];
        for (int j = 1;j < 5 ;j++)
            r[i] += ((uint128_t) 19 * f_coeff[j%5]) * g_coeff[(5+j-i)%5];
    }
    
    for (int i = 0; i < 4; ++i) 
    {
        r[i] &= mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
    }
    
    carry = (uint64_t) (r[4] >> 51); 
    r[4] &= mask;
    r[0] += 19ULL * carry;
    carry = r[0] >> 51;
    r[0] &= mask;
    r[1] += carry;
    carry = r[1] >> 51;
    r[1] &= mask;
    r[2] += carry;

     for (int i = 0; i < 5; ++i)
     {
        h[i] = (uint64_t) r[i];
     }
}