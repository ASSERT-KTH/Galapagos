void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) 
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t temp[5], mult[4];
    uint64_t carry, h_temp[5];
    
    for (int i = 0; i < 5; i++) 
    {
        temp[i] = (uint128_t) f[i];
        if(i < 4) mult[i] = ((uint128_t) 19ULL) * f[i+1];
    }

    temp[1] = mult[0];

    // Compute the multiplication results
    for (int i = 0; i < 5; i++) 
    {
        h_temp[i] = temp[0] * g[i] + 
                      mult[(4 - i)%4] * g[(5 - i)%5] + 
                      mult[(3 - i)%4] * g[(4 - i)%5] + 
                      mult[(2 - i)%4] * g[(3 - i)%5] + 
                      mult[(1 - i)%4] * g[(2 - i)%5];
                    
        h_temp[i] %= mask;
        carry = h_temp[i] / (uint128_t)(1ULL<<51);
        
        if(i != 4)
        {
            h_temp[i+1] += carry;
        }
        else
        {
            h_temp[0] += 19ULL * carry;
            h_temp[0] %= mask;
            
            carry = h_temp[0] / (uint128_t)(1ULL<<51);
            h_temp[1] += carry;
        }
    }
  
    // Assign the results to h
    for (int i = 0; i < 5; i++) 
    {
        h[i] = h_temp[i];
    }

}