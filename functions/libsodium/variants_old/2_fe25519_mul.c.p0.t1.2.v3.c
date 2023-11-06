fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_arr[5];
    uint128_t f_mul19[4];
    uint128_t g_arr[5];
    uint64_t  r_values[5];
    uint64_t  carry;
    
    for(int idx = 0; idx < 5; ++idx)
    {
        f_arr[idx] = (uint128_t) f[idx];
        if(idx < 4){
            f_mul19[idx] = 19ULL * ((uint128_t) f[idx+1]);
        }
        g_arr[idx] = (uint128_t) g[idx];
    }

    for(int idx = 0; idx < 5; ++idx)
    {
        r[idx] = f_arr[0] * g_arr[idx] +
                 ((idx==0) ?  0 : ((idx==1) ? f_arr[1]*g_arr[0]? f_mul19[idx-2]*g_arr[4-idx])) +
                 ((idx==0) ?  0 : ((idx<  3) ? f_mul19[idx-1]*g_arr[3-idx])) +
                 ((idx<  2) ?  0 : f_mul19[idx-0]*g_arr[2-idx]) +
                 ((idx < 4) ? f_mul19[idx+1]*g_arr[1-idx] : f_arr[4]*g_arr[0]);
    }
    
    for(int i=0; i < 5; i++) 
    {
        r_values[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
        r_values[i+1]   = ((uint64_t) r[i+1]) & mask;   
        r[i+1]         += carry;
        r_values[i+1]  += ((i < 4) ? carry : 19ULL * carry);
        carry  = r_values[i+2] >> 51;   
        r_values[i+2]   = ((uint64_t) r[i+2]) & mask;
        r_values[i+3]  += carry;
    }

    for(int idx = 0; idx < 5; ++idx)
    {
        h[idx] = r_values[idx];
    }
}