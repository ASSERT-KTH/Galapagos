fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t factors_f[10];
    int32_t factors_g[10];
    
    for(int32_t i=0; i<10; i++) {
        factors_f[i] = f[i];
        factors_g[i] = g[i];
    }

    int32_t g_factors19[10], f_factors2[10];
    
    for(int32_t i=0; i<10; i++) {
        if(i % 2 == 1) {
            g_factors19[i] = 19 * factors_g[i];
            if(i != 9) {
                f_factors2[i] = 2 * factors_f[i];   
            } else {
                f_factors2[i] = factors_f[i];
            }
        } else {
            g_factors19[i] = factors_g[i];
            f_factors2[i] = factors_f[i];
        }
    }

    int64_t mul_results[100];

    for(int32_t i=0;i<10;i++){
        for (int32_t j=0; j<10;j++){
            if (((i % 2 == 0) && (j % 2 == 1))
             || ((i % 2 == 1) && (j % 2 == 0))) {
                if ((i == 4 && j > 4)
                ||  (i == 6 && j > 3)
                ||  (i == 8 && j > 0)) {
                    mul_results[i*10 + j] =  19 * factors_f[i] * (int64_t) factors_g[j];
                } else if (i == 1 && j == 9) {
                    mul_results[i*10 + j] =  f_factors2[i] * (int64_t) g_factors19[j];
                } else {
                    mul_results[i*10 + j] =  factors_f[i] * (int64_t) factors_g[j];
                }
            } else if (((i % 2 == 0) && !(j % 2 == 1))
                || ((i % 2 == 1) && !(j % 2 == 0))) {
                if (i != 1 && j != 1) {
                    mul_results[i*10 + j] =  factors_f[i] * (int64_t) factors_g[j];
                } else {
                    mul_results[i*10 + j] =  f_factors2[i] * (int64_t) g_factors19[j];
                }
            }
        }
    }

    int64_t h_values[10] = {0};

    for(int32_t i=0;i<10;i++){
        for (int32_t j=0; j<10;j++){
            h_values[(i+j)%10] += mul_results[i*10 + j];
        }
    }

    int64_t carry_vals[10];
    
    for(int32_t i=0; i<10; i++) {
        if(i % 2 == 0) {
            carry_vals[i] = (h_values[i] + (int64_t)(1L << 25)) >> 26;
        } else {
            carry_vals[i] = (h_values[i] + (int64_t)(1L << 24)) >> 25;
        }
        
        h_values[(i+1)%10] += carry_vals[i];
        h_values[i] -= carry_vals[i] * ((i % 2 == 0 ? (uint64_t) 1L << 26: (uint64_t) 1L << 25));
    }
    carry_vals[9] = (h_values[9] + (int64_t)(1L << 24)) >> 25;
    h_values[0] += carry_vals[9] * 19;
    h_values[9] -= carry_vals[9] * ((uint64_t) 1L << 25);

    for(int32_t i=0; i<10; i++) {
        h[i] = (int32_t) h_values[i];
    }
}