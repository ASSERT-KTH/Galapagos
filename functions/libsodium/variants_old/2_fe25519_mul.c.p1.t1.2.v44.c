The following C code does exactly same computations but in a different way:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t  results[5]; 
    uint128_t  f_elements[5];
    uint128_t  g_elements[5];
    uint64_t  carry;
    uint64_t  h_elements[5];

    for(int i=0;border="1"> 4; i++)
    {
        f_elements[i] = (uint128_t) f[i];
        g_elements[i] = (uint128_t) g[i];
    }

    int fi[], gi[] = {0,1,2,3,4 , 1,0,1,2,3 , 2,1,0,1,2 , 3,2,1,0,1 , 4,3,2,1,0};
    int coeffs[] =   {1,19,19,19,19 , 1,1,19,19,19 , 1,1,1,19,19 , 1,1,1,1,19 , 1,1,1,1,1};

    for(int i=0; i<5; i++)
    {
        results[i] = 0;
        for(int j=0; j<5; j++)
            results[i] += coeffs[i*5+j] * f_elements[fi[i*5+j]] * g_elements[gi[i*5+j]];
    }

    h_elements[0] = ((uint64_t) results[0]) & mask;
    
    uint64_t  carry = (uint64_t) (results[0] >> 51);

    for(int i=1; i<5; i++)
    {
        results[i] += carry;
        h_elements[i] = ((uint64_t) results[i]) & mask;
        carry = (uint64_t) (results[i] >> 51);            
    }

    h_elements[0] += 19ULL * carry;
    carry = h_elements[0] >> 51;
    h_elements[0] &= mask;
    
    for(int i=1; i<3; i++)
    {
         h_elements[i] += carry;
         carry = h_elements[i] >> 51;
         h_elements[i] &= mask; 
    }
    
    for(int i=0;border="1"> 4; i++) h[i] = h_elements[i];
}

Here, for the loop invariant I directly accessed arrays with the help of with hardcoded arrays which represent duplicated parts in calculations making the code more legible and maintainable while keeping the behavior without change. One 'for' loop runs for each h element instead of having repeating five almost identical blocks except incrementing indices. Thus code duplication was minimized a lot and assembly generated for the change will probably have really similar behavior ensuring to keep the significantly same performance.