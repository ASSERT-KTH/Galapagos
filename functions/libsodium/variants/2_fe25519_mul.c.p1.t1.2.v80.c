void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t elements[5] = {0, 1, 2, 3, 4};
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], temp_f[5], temp_g[5], carry;
    
    for(int i = 0; i < 5; i++)
    {
        temp_f[i] = (uint128_t) f[i];
        temp_g[i] = (uint128_t) g[i];
    }

    r[0] = temp_f[0] * temp_g[0] + 19ULL * ((temp_g[4] * temp_f[1]) + (temp_g[3] * temp_f[2]) + (temp_g[2] * temp_f[3]) + (temp_g[1] * temp_f[4]));

    for(int i = 1; i < 5; i++){
        r[i] = temp_f[0] * temp_g[i] + temp_f[i] * temp_g[0] + 
               19ULL * ((temp_g[(i+3)%5] * temp_f[(i+1)%5]) + (temp_g[(i+2)%5] * temp_f[(i+2)%5])) +
               temp_g[(i+1)%5] * temp_f[(i+3)%5] + temp_g[(i+4)%5] * temp_f[(i+4)%5];
    }

    for(int i = 0; i < 5; i++)
    {
        r[(i+1)%5] += (carry = static_cast<uint64_t>(r[i] >> 51)); // Variable named carry (uint128_t) declared implicitly. Carryover bits added to next value.
        r[i] = static_cast<uint64_t>((r[i]) & mask);
        carry = r[(i+1)%5] >> 51;
        r[(i+1)%5] &= mask;
    }
    
    r[0] += (static_cast<uint64_t>(19ULL * carry));
    
    carry = r[0] >> 51;
    r[0] &= mask;
    r[1] += carry;
          
    if (r[1] >> 51){
        r[0] += carry;
    }
    
    for(int i = 0; i < 5; i++)
    {
        h[i] = r[i];
    }
}