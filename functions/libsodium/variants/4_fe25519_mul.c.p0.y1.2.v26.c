void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], fg[5], temp, carry = 0;

    for(int j = 0; j < 5; ++j)
        fg[j] = (uint128_t) f[j] * (j ? 19 : 1);

    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
            r[i] += fg[j] * g[(i - j + 4) % 4] * (j <= i ? 1 : 19 );
        
        carry = (uint64_t)(r[i] >> 51);
        if(i < 4) r[i+1] += carry;
        h[i] = r[i] &= mask;
    }
    
    h[0] += 19ULL * carry;
    
    for(int i = 0; i < 5; ++i)
    {
        carry = h[i] >> 51;
        h[i] &= mask;
        if(i < 4) h[i+1] += carry;
    }   
}