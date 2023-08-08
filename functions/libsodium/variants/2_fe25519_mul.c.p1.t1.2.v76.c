fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_values[5] = {(uint128_t) f[0], (uint128_t) f[1], (uint128_t) f[2], 
                             (uint128_t) f[3], (uint128_t) f[4]};
    uint128_t g_values[5] = {(uint128_t) g[0], (uint128_t) g[1], (uint128_t) g[2], 
                             (uint128_t) g[3], (uint128_t) g[4]};
    uint128_t results[5], multiply[5], w;
    uint64_t h_result[5];
    uint64_t  carry;
    int i, j;

    for (i = 0; i < 5; i++) {
        multiply[i] = (i == 0) ? f_values[i] : 19ULL * f_values[i];
    }

    for(i = 0; i < 5; i++) {
        results[i] = 0ULL;
        for(j = 0; j < 5; j++) {
            w = ((i + j) >= 5) ? multiply[(i + j) % 5] : f_values[(i + j) % 5];
            results[i] += w * g_values[(5 + j - i) % 5];
        }   
    }

    for(i = 0; i < 5; i++) {
        h_result[i]   =  (uint64_t) (results[i]) & mask;
        carry   =  (uint64_t) (results[i] >> 51);
        results[(i + 1) % 5] += carry;
        h_result[i]   &= mask;
        h[i] =  h_result[i];
        if(i == 4) {
            h_result[0] += 19 * carry;
        } else {
            h_result[(i + 1) % 5] += carry ; 
        } 
    }
}