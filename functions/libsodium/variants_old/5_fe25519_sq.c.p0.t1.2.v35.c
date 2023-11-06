fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_values[5];
    uint128_t double_f[2];
    uint128_t times_f[5];
    uint64_t  result_r[5];
    uint64_t  carry;

    for (int i=0; i < 5; i++) f_values[i] = (uint128_t) f[i];

    double_f[0] = f_values[0] << 1;
    double_f[1] = f_values[1] << 1;

    for (int i = 1; i < 4; i += 2){
        times_f[i]  = 38ULL * f_values[i];
        times_f[i] /= 2;
    }

    times_f[3] = 19ULL * f_values[3];
    times_f[4] = 19ULL * f_values[4];

    r[0] =   f_values[0] * f_values[0]        + times_f[1] * f_values[4] + times_f[2] * f_values[3];
    r[1] = double_f[0]    * f_values[1]        + times_f[2] * f_values[4] + times_f[3];
    r[2] = double_f[0]    * f_values[2] + pow(f_values[1], 2) + times_f[4] * f_values[4];
    r[3] = double_f[0]    * f_values[3] + double_f[1] * f_values[2]        + pow(f_values[4], 2);
    r[4] = double_f[0]    * f_values[4] + double_f[1] * f_values[3] + pow(f_values[2], 2);

    for(int i = 0; i < 5; i++){ 
        result_r[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        
        if(i != 4) r[i + 1] += carry;
        
        if(i == 4){
            result_r[0] += 19ULL * carry;
            carry  = result_r[0] >> 51;
            result_r[0] &= mask;
            result_r[1] += carry;
            carry  = result_r[1] >> 51;
            result_r[1] &= mask;
            result_r[2] += carry;
        }
    }

    for(int i = 0; i < 5; i++) h[i] = result_r[i];
}
