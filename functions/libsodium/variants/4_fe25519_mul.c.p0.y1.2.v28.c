void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint64_t carry;
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_values[5], g_values[5], mul_values[5];
    uint128_t prof_values[5], prod_results[5];
    
    for(int i = 0;i < 5; i++){
        f_values[i] = (uint128_t) f[i];
        g_values[i] = (uint128_t) g[i];
    }

    prof_values[0] = 19ULL * f_values[1];
    prof_values[1] = 19ULL * f_values[2];
    prof_values[2] = 19ULL * f_values[3];
    prof_values[3] = 19ULL * f_values[4];

    mul_values[0] = f_values[0] * g_values[0] + prof_values[0] * g_values[4] + prof_values[1] * g_values[3]
                    + prof_values[2] * g_values[2] + prof_values[3] * g_values[1];
    mul_values[1] = f_values[0] * g_values[1] + f_values[1] * g_values[0] + prof_values[1] * g_values[4] 
                    + prof_values[2] * g_values[3] + prof_values[3] * g_values[2];
    mul_values[2] = f_values[0] * g_values[2] + f_values[1] * g_values[1] + f_values[2] * g_values[0] 
                    + prof_values[2] * g_values[4] + prof_values[3] * g_values[3];
    mul_values[3] = f_values[0] * g_values[3] + f_values[1] * g_values[2] + f_values[2] * g_values[1] 
                    + f_values[3] * g_values[0] + prof_values[3] * g_values[4];
    mul_values[4] = f_values[0] * g_values[4] + f_values[1] * g_values[3] + f_values[2] * g_values[2] 
                    + f_values[3] * g_values[1] + f_values[4] * g_values[0];
                    
    for(int i = 0;i < 5; i++){
        prod_results[i]   = ((uint64_t) mul_values[i]) & mask;
        carry  = (uint64_t) (mul_values[i] >> 51);
        h[i] = prod_results[i];
        if(i < 4) mul_values[i+1] += carry;
        else{
            carry  = prod_results[0] >> 51;
            prod_results[0] &= mask;
            prod_results[1] += carry;
            carry  = prod_results[1] >> 51;
            prod_results[1] &= mask;
            prod_results[2] += carry;
        }
    }
}