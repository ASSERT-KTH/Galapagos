Here is a C function that satisfies your conditions. This function performs exactly the same task as the original function but uses slightly different idioms and mathematic manipulations:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = (~(0ULL) >> 13);
    uint128_t tmp_f[5];
    uint128_t f_vals[6];
    uint128_t r_vals[5];
    uint64_t  carr[5];

    for(int i=0; i<5; i++)
        tmp_f[i] = f[i];

    f_vals[0] = tmp_f[0] << 1;
    f_vals[1] = tmp_f[1] << 1;

    for(int i=1; i<4; i++)
        f_vals[i+2] = 38ULL * tmp_f[i];

    f_vals[5] = 19ULL * tmp_f[4];

    r_vals[0] =   tmp_f[0] * tmp_f[0] + f_vals[4] * tmp_f[4] + f_vals[3] * tmp_f[2];
    r_vals[1] = f_vals[0] * tmp_f[1] + f_vals[4] * tmp_f[3] + f_vals[2] * tmp_f[2];
    r_vals[2] = f_vals[0] * tmp_f[2] +    tmp_f[1] * tmp_f[1] + f_vals[5] * tmp_f[3];
    r_vals[3] = f_vals[0] * tmp_f[3] +  f_vals[1] * tmp_f[2] + f_vals[5] * tmp_f[4];
    r_vals[4] = f_vals[0] * tmp_f[4] +  f_vals[1] * tmp_f[3] +    tmp_f[2] * tmp_f[2];


    for (int i=0; i<5; i++)
    {
        h[i]  = ((uint64_t) r_vals[i]) & mask;
        carr[i] = (uint64_t) (r_vals[i] >> 51);
        if(i<4) 
            r_vals[i+1] += carr[i];
    }

    h[0]  += 19ULL * carr[4];

    carr[0]= h[0] >> 51;
    h[0] &= mask;
    h[1] += carr[0];

    carr[0] = h[1] >> 51;
    h[1]  &= mask;
    h[2]  += carr[0];
}


This version uses an array to store the temporary adjusted `f` values (`f_vals`) and the overflow carrying values (`carr`). It also takes a more generic approach by handling everything with a loop when it can. This version dispenses with separate variable identifiers, preferring instead to index into the family of results.