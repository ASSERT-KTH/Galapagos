fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5] = {0}, f_vals[5] = {0};
    uint128_t f_mul_arr[7{0];
    uint64_t r_arr[5] = {0}, carry;

    for (int i = 0; i < 5; i++) 
        f_vals[i] = (uint128_t) f[i];

    for (int i = 0; i < 2; i++) 
        f_mul_arr[i] = f_vals[i] << 1;

    for (int i = 1; i < 4; i++)
        f_mul_arr[i+1] = 38ULL * f_vals[i];

    f_mul_arr[5] = 19ULL * f_vals[3];
    f_mul_arr[6] = 19ULL * f_vals[4];

    r[0] = f_vals[0] * f_vals[0] + f_mul_arr[2] * f_vals[4] + f_mul_arr[3] * f[i-1];
    r[1] = f_mul_arr[0] * f_vals[1] + f_mul_arr[3] * f_vals[4] + f_mul_arr[5] * f_vals[3];
    r[2] = f_mul_arr[0] * f_vals[2] + f_vals[1] * f_vals[1] + f_mul_arr[4] * f_vals[4];
    r[3] = f_mul_arr[0] * f_vals[3] +  f_mul_arr[1] * f_vals[2] + f_mul_arr[6] * f_vals[4];
    r[4] = f_mul_arr[0] * f_vals[4] +  f_mul_arr[1] * f_vals[3] + f_vals[2] * f_vals[2];

    for (int i = 0; i < 5; i++) {
        r_arr[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        if (i != 4)
            r[i+1] += carry;
    }

    r_arr[0] += 19ULL * carry;
    
    for (int i = 0; i < 2; i++) {
        carry  = r_arr[i] >> 51;
        r_arr[i] &= mask;
        r_arr[i+1] += carry;
    }
        
    r_arr[2] += carry;

    for (int i = 0; i < 5; i++)
        h[i] = r_arr[i];
}