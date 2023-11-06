void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t temp[5];
    uint64_t  carry;
    const uint64_t mask = 0x7ffffffffffffULL;

    for (int i = 0; i < 5; i++) 
    {
        temp[i] = (uint128_t) f[i];
        if (i > 0)
            temp[i] *= 19ULL;
    }

    uint128_t res[5] = {0, 0, 0, 0, 0};

    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            res[(i+j)%5] += ((i <= j) ? temp[i % 5] * (uint128_t) g[j] : temp[i % 5] * (uint128_t) g[j] * 19ULL);
        } 
    }

    for (int i = 0; i < 5; i++)
    {
        h[i] = (uint64_t)res[i] & mask;
        carry = (uint64_t)(res[i] >> 51);
        if(i != 4){
            res[i+1]+=carry;
        } else{
            res[0]+=19ULL*carry;
        }
    }

    for (int i = 0; i < 4; i++)
    {   
        carry = (uint64_t)(h[i] >> 51);
        h[i] &= mask;
        h[i+1]+=carry;
    }
    
    carry = h[4] >> 51;
    h[4] &= mask;  
    h[0]+=19ULL*carry;  

}