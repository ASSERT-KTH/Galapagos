fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f_values[5], g_values[5];
    uint128_t f_nineteen[4];
    uint64_t  r_vals[5];
    uint64_t  carry;

    for(int i=0; i < 5; i++) {
        f_values[i] = (uint128_t)f[i];
        g_values[i] = (uint128_t)g[i];   
    }

    for(int j=1; j < 5; j++) {
        f_nineteen[j-1] = 19ULL * f_values[j];
    }

    r0 = f_values[0] * g_values[0] + f_nineteen[0] * g_values[4] + f_nineteen[1] * g_values[3] + f_nineteen[2] * g_values[2] + f_nineteen[3] * g_values[1];
    r1 = f_values[0] * g_values[1] + f_values[1] * g_values[0] + f_nineteen[1] * g_values[4] + f_nineteen[2] * g_values[3] + f_nineteen[3] * g_values[2];
    r2 = f_values[0] * g_values[2] + f_values[1] * g_values[1] + f_values[2] * g_values[0] + f_nineteen[2] * g_values[4] + f_nineteen[3] * g_values[3];
    r3 = f_values[0] * g_values[3] + f_values[1] * g_values[2] + f_values[2] * g_values[1] + f_values[3] * g_values[0] + f_nineteen[3] * g_values[4];
    r4 = f_values[0] * g_values[4] + f_values[1] * g_values[3] + f_values[2] * g_values[2] + f_values[3] * g_values[1] + f_values[4] * g_values[0];

    for(int k=0; k < 5; k++){
        if(k == 0){
            r_vals[k]    = ((uint64_t) r0) & mask;
        }else if(k == 1){
            r_vals[k]    = (r1) & mask;
        }else if(k == 2){
            r_vals[k]    = (r2) & mask;
        }else if(k == 3){
            r_vals[k]    = (r3) & mask;
        }else if(k == 4){
            r_vals[k]    = (r4) & mask;
        }

        carry  = (r_vals[k] + carry) >> 51;
        r_vals[(k + 1)%5]    += carry;
    }

    r_vals[0]   += 19ULL * carry;
    carry  = r_vals[0] >> 51;
    r_vals[0]   &= mask;
    r_vals[1]   += carry;
    carry  = r_vals[1] >> 51;
    r_vals[1]   &= mask;
    r_vals[2]   += carry;

    for(int l=0; l < 5; l++) {
        h[l] = r_vals[l];
    }

}