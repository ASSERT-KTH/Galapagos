fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t g0, g1, g2, g3, g4;
    uint128_t f0, f1, f2, f3, f4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    // Load f's and g's to local variable
    
    for (int i = 0; i < 5; ++i) 
    {
        (&f0)[i] = (uint128_t) f[i];
        (&g0)[i] = (uint128_t) g[i];
    }

    // Calculate multipled values

    for(int i = 0 ; i < 5 ; ++i) 
    {
        (&r0)[i] = f0 * (&g0)[i]
                 + 19ULL * ((i == 0 ? 0 : f1 * (&g0)[4 - i + 1]))
                 + 19ULL * ((i < 2  ? 0 : f2 * (&g0)[4 - i + 2]))
                 + 19ULL * ((i < 3  ? 0 : f3 * (&g0)[4 - i + 3]))
                 + 19ULL * ((i < 4  ? 0 : f4 * (&g0)[4 - i + 4]));
    }
    

    for(int i = 0 ; i < 5 ; ++i)
    { 
        (&r00)[i]    = ((uint64_t) (&r0)[i]) & mask;
        carry  = (&r0)[i] >> 51;
        if(i != 4) 
        {
            (&r0)[i + 1] += carry;
        } 
        else 
        {
            r00 += 19ULL * carry;
            carry  = r00 >> 51;
            r00   &= mask;
            r01   += carry;
        }
        carry  = (&r00)[i] >> 51;
        (&r00)[i]   &= mask;
        if(i != 4) 
        {
           (&r00)[i + 1]   += carry;
        }        
    }

   // Copy back results
    for(int i = 0 ; i < 5 ; ++i)
    {
        h[i] = (&r00)[i];
    }

}