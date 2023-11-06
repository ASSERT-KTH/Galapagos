fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], temp_f[5], temp_g[5], f_19[4];
    uint64_t  r_res, carry;

    for (int i = 0; i < 5; i++) {
        temp_f[i] = (uint128_t) f[i];
        temp_g[i] = (uint128_t) g[i];
    }
    
    for (int i = 1; i < 5; i++) {
        f_19[i - 1] = 19ULL * temp_f[i]; 
    }

    r[0] = temp_f[0] * temp_g[0] + f_19[0] * temp_g[4] + f_19[1] * temp_g[3] + f_19[2] * temp_g[2] + f_19[3] * temp_g[1];
    r[1] = temp_f[0] * temp_g[1] + temp_f[1] * temp_g[0] + f_19[1] * temp_g[4] + f_19[2] * temp_g[3] + f_19[3] * temp_g[2];
    r[2] = temp_f[0] * temp_g[2] + temp_f[1] * temp_g[1] + temp_f[2] * temp_g[0] + f_19[2] * temp_g[4] + f_19[3] * temp_g[3];
    r[3] = temp_f[0] * temp_g[3] + temp_f[1] * temp_g[2] + temp_f[2] * temp_g[1] + temp_f[3] * temp_g[0] + f_19[3] * temp_g[4];
    r[4] = temp_f[0] * temp_g[4] + temp_f[1] * temp_g[3] + temp_f[2] * temp_g[2] + temp_f[3] * temp_g[1] + temp_f[4] * temp_g[0];

    for(int i = 0;  i < 5; i++){
        r_res = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        if(i != 4){
            r[i+1]+= carry;
        }
        r[i] = r_res;
    }
    carry  = r[0] >> 51;
    r[0]  &= mask;
    r[1] += carry;
    carry  = r[1] >> 51;
    r[1] &= mask;
    r[2] += carry;

    for(int i = 0;  i < 5; i++){
        h[i] = r[i];                                                  
    }
}