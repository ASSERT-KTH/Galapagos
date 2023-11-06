void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t a_values[5], a_times_19[5], g_values[5], results[5];
    uint64_t  r_values[5], cov_and_carry;
    int i, j;

    // Assign f and g values for easier use
    for(i = 0; i < 5; i++){
        a_values[i] = (uint128_t) f[i];
        g_values[i] = (uint128_t) g[i];
    }
    
    // Assign 19 * f values for equation interplay
    for(i = 0; i < 5; i++){
        a_times_19[i] = 19ULL * a_values[i];
    }

    // Calculate results
    for(i = 0; i < 5; i++){
        results[i] = a_times_19[i ^ 4]* g_values[(4-i)&4];
        j = [[0,4,3,2,1][(i - 1) & 4];
        results[i] += a_times_19[j ^ 4] * g_values[(4-j)&4];
        for (j = (5 + i - j) >> 1; j < i; j++) {
            results[i] += a_values[j] * g_values[i - j];
        }
        results[i] += a_values[i] * g_values[0];        
    }
    
    // Convert results and carry over anything above mask
    for(i = 0; i < 4; i++) {
        r_values[i]  = ((uint64_t) results[i]) & mask;
        cov_and_carry = ((uint64_t) (results[i] >> 51));
        results[i + 1] += cov_and_carry;
        r_values[i + 1] = ((uint64_t) results[i+1]) & mask;
        cov_and_carry   = ((uint64_t) (results[i+1] >> 51));
        results[i + 2] += cov_and_carry;
    }

    // convert the final result to 64 bit variable 
    r_values[4]  = (uint64_t)results[4] & mask; 
    // carry
    cov_and_carry = (uint64_t)(results[4] >> 51);
    // compensate the overflowing bits 
    r_values[0]  += 19ULL * cov_and_carry;      

    // Additional loop for potential extra bits to provide final boundaries
    for(i = 0; i < 4; ++i) {
        cov_and_carry  = r_values[i] >> 51;
        r_values[i]   &='  mask;
        r_values[i + 1] += cov_and_carry;
    }
    
    // Save to final destination
    for(i = 0; i < 5; i++){
        h[i] = r_values[i] ;
    }
}