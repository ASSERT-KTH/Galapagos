void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_elements[5], f_multipliers[7];
    uint128_t results[5];
    uint64_t r_temp[5], carry;

    for (int i=0; i<5; i++) {
        f_elements[i] = (uint128_t) f[i];
    }

    f_multipliers[0] = f_elements[0] << 1;
    f_multipliers[1] = f_elements[1] << 1;
    f_multipliers[2] = 38ULL * f_elements[1];
    f_multipliers[3] = 38ULL * f_elements[2];
    f_multipliers[4] = 38ULL * f_elements[3];
    f_multipliers[5] = 19ULL * f_elements[3];
    f_multipliers[6] = 19ULL * f_elements[4];

    results[0] =   f_elements[0] * f_elements[0] + f_multipliers[2] * f_elements[4] + f_multipliers[3] * f_elements[3];
    results[1] = f_multipliers[0] * f_elements[1] + f_multipliers[3] * f_elements[4] + f_multipliers[5] * f_elements[3];
    results[2] = f_multipliers[0] * f_elements[2] +    f_elements[1] * f_elements[1] + f_multipliers[4] * f_elements[4];
    results[3] = f_multipliers[0] * f_elements[3] +  f_multipliers[1] * f_elements[2] + f_multipliers[6] * f_elements[4];
    results[4] = f_multipliers[0] * f_elements[4] +  f_multipliers[1] * f_elements[3] +    f_elements[2] * f_elements[2];

    r_temp[0] = ((uint64_t) results[0]) & mask;
    carry  = (uint64_t) (results[0] >> 51);
    results[1] += carry;
    r_temp[1] = ((uint64_t) results[1]) & mask;
    carry  = (uint64_t) (results[1] >> 51);
    results[2] += carry;
    r_temp[2] = ((uint64_t) results[2]) & mask;
    carry  = (uint64_t) (results[2] >> 51);
    results[3] += carry;
    r_temp[3] = ((uint64_t) results[3]) & mask;
    carry  = (uint64_t) (results[3] >> 51);
    results[4] += carry;
    r_temp[4] = ((uint64_t) results[4]) & mask;
    carry  = (uint64_t) (results[4] >> 51);

    r_temp[0] += 19ULL * carry;
    carry  = r_temp[0] >> 51;
    r_temp[0]   &= mask;
    r_temp[1] += carry;
    carry  = r_temp[1] >> 51;
    r_temp[1]   &= mask;
    r_temp[2] += carry;

    for(int i=0;i<5;i++){
        h[i] = r_temp[i];
    }
}