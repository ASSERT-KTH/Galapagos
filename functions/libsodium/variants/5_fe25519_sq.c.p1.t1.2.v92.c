Here is a function variant that still uses the same logic but reduces redundancy in the code by abstracting certain steps into for-loops. This provides a more concise solution.


void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_vals[5];
    uint64_t  r_fin[5];
    uint64_t  carry;
    int i;

    for (i = 0; i < 5; i++)
        f_vals[i] = (uint128_t) f[i];
    
    r[0] =   f_vals[0] * f_vals[0] + 38ULL * f_vals[1] * f_vals[4] + 38ULL * f_vals[2] * f_vals[3];
    r[1] = f_vals[0] * f_vals[1] * 2 + 38ULL * f_vals[2] * f_vals[4] + 19ULL * f_vals[3] * f_vals[3];
    r[2] = f_vals[0] * f_vals[2] * 2 +    f_vals[1] * f_vals[1] + 38ULL * f_vals[3] * f_vals[4];
    r[3] = f_vals[0] * f_vals[3] * 2 +  f_vals[1] * f_vals[2] * 2 +  19ULL * f_vals[4] * f_vals[4 ];
    r[4] = f_vals[0] * f_vals[4] * 2 +  f_vals[1] * f_vals[3] * 2 +         f_vals[2] * f_vals[2];
    
    for (i = 0; i < 5; i++)
    {
        r_fin[i] = ((uint64_t) r[i]) & mask;
        carry  = r[i] >> 51;
        if (i < 4) 
            r[i + 1] += carry;
        else 
            r_fin[0] += 19ULL * carry;

        if (i > 0) 
        {
            carry  = r_fin[i - 1] >> 51;
            r_fin[i - 1] &= mask;
            r_fin[i] += carry;
        }
        h[i] = r_fin[i];
    }
}


In this variant, square arrays are used to hold the same values and simplify and condense the operations within the function. In addition, appropriate loops are used where feasible. The functionality however, still remains the same.