fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint64_t r00, r01, r02, r03, r04;
    uint64_t carry;
    uint128_t f_vals[5], f_params[7];
    const uint64_t constants1[2] = {1ULL, 38ULL};
    const uint64_t constants2[2] = {38ULL, 19ULL};
    const uint64_t constant19 = 19ULL;

    for(int i = 0; i < 5; i++) {
        f_vals[i] = (uint128_t) f[i];
    }

    f_params[0] = f_vals[0] << 1;
    f_params[1] = f_vals[1] << 1;
    for(int i = 1; i < 4; i++){
        f_params[i+1] = constants1[i != 2] * f_vals[i];
    }
    for(int i = 2; i < 5; i++){
        f_params[i+2] = constants2[i < 4] * f_vals[i];
    }

    r0 =   f_vals[0] * f_vals[0] + f_params[2] * f_vals[4] + f_params[3] * f_vals[3];
    r1 = f_params[0] * f_vals[1] + f_params[4] * f_vals[4] + f_params[6] * f_vals[3];
    r2 = f_params[0] * f_vals[2] +    f_vals[1] * f_vals[1] + f_params[5] * f_vals[4];
    r3 = f_params[0] * f_vals[3] +  f_params[1] * f_vals[2] + f_params[6] * f_vals[4];
    r4 = f_params[0] * f_vals[4] +  f_params[1] * f_vals[3] +    f_vals[2] * f_vals[2];

    uint64_t r_vals[5] = {(uint64_t) r0, (uint64_t) r1, (uint64_t) r2, (uint64_t) r3, (uint64_t) r4};
    uint128_t sums[5] = {r0, r1, r2, r3, r4};

    for (int i = 0; i < 5; i++) {
        r_vals[i] = r_vals[i] & mask;
        carry  = (uint64_t) (sums[i] >> 51);
        sums[i+1]  += carry;
    
        if(i>=3 && i <= 4) {
            int notLast = (i != 4)? 1:-1;
            r_vals[i-notLast] += constant19 * carry;
            carry  = r_vals[i-notLast] >> 51;
            r_vals[i-notLast]   &= mask;
            r_vals[i]   += carry;
            carry  = r_vals[i] >> 51;
            r_vals[i]   &= mask;
            r_vals[notLast == -1? 2 : (i +1)]   += carry;
        }
        h[i] = r_vals[i];
    }
}