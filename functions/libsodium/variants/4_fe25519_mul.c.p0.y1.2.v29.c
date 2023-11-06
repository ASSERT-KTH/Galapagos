void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) 
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t temp [5];
    uint128_t f_mult[5], g_mult[5];

    for(int i = 0; i < 5; i++)
    {
        f_mult[i] = (uint128_t) f[i];
        g_mult[i] = (uint128_t) g[i];
    }

    for(int i = 1; i < 5; i++)
        f_mult[i] *= 19ULL;

    for(int i = 0; i < 5; i++)
    {
        temp[i] = f_mult[0] * g_mult[i];
        for(int j = 1; j <= i; j++)
        {
            temp[i] += f[j] * g_mult[i - j];
        }
        if(i < 4)
            temp[i] += f_mult[i + 1] * g[0]; 
            
        h[i]  = (uint64_t) (temp[i] & mask);
        uint64_t carry = (uint64_t) (temp[i] >> 51);
        if (i < 4) 
            temp[i + 1] += carry;
        else 
        {
            h[0] += carry * 19ULL;
            carry = h[0] >> 51;
            h[0] &= mask;
            h[1] += carry;
        }  
    }
    uint64_t carry  = h[1] >> 51;
    h[1] &= mask;
    h[2] += carry;
}