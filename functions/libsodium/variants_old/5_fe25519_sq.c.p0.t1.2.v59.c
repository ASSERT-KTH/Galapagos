fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f_vals[5];
    uint128_t f_vals_times2[2], f_vals_times38[3];
    uint64_t  r_vals[5];
    uint64_t  carry;

    for (uint8_t i = 0; i < 5; i++) {
        f_vals[i] = (uint128_t) f[i];
    }

    for (uint8_t i = 0; i < 2; i++) {
        f_vals_times2[i] = f_vals[i] << 1;
    }

    for (uint8_t i = 0; i < 3; i++) {
        f_vals_times38[i] = 38ULL * f_vals[i+1];
    }

    r0 = f_vals[0] * f_vals[0] + 38ULL * f_vals[1] * f_vals[4] + 38ULL * f_vals[2] * f_vals[3];
    r1 = f_vals_times2[0] * f_vals[1] + 38ULL * f_vals[2] * f_vals[4] + 19ULL * f_vals[3] * f_vals[3];
    r2 = f_vals_times2[0] * f_vals[2] + f_vals[1] * f_vals[1] + 38ULL * f_vals[3] * f_vals[4];
    r3 = f_vals_times2[0] * f_vals[3] + f_vals_times2[1] * f_vals[2] + 19ULL * f_vals[4] * f_vals[4];
    r4 = f_vals_times2[0] * f_vals[4] + f_vals_times2[1] * f_vals[3] + f_vals[2] * f_vals[2];

    for (uint8_t i = 0; i < 5; i++)
    {
        r_vals[i] = ((uint64_t) r1) & mask;
        carry  = (uint64_t) (r1 >> 51);
        if(i!=4){
            uint64_t temp_def = i+1;
            temp_def += carry;
            temp_def = ((uint64_t) temp_def) & mask;
            carry  = (uint64_t) (temp_def >> 51);
            temp_def += carry;
        }
        r_vals[0] += 19ULL * carry; carry = r_vals[0] >> 51; r_vals[0] &= mask;    
        r_vals[1] += carry; carry = r_vals[1] >> 51; r_vals[1] &= mask; 
        if(i==3){
            f[2]=r_vals[2] += carry;
        }
    }
    

    for (uint8_t i = 0; i < 5; i++) {
        h[i] = r_vals[i];
    }

}