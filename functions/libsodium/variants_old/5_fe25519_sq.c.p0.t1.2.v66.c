fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_elements[5];
    uint128_t two_times_f0, two_times_f1, f1_by_38, f2_by_38, f3_by_38, f3_by_19, f4_by_19;
    uint64_t  carry;

    for(int i=0; i<5; i++) {
        f_elements[i] = (uint128_t) f[i];
    }

    two_times_f0 = f_elements[0] << 1;
    two_times_f1 = f_elements[1] << 1;

    f1_by_38 = 38ULL * f_elements[1];
    f2_by_38 = 38ULL * f_elements[2];
    f3_by_38 = 38ULL * f_elements[3];

    f3_by_19 = 19ULL * f_elements[3];
    f4_by_19 = 19ULL * f_elements[4];

    r[0] = f_elements[0] * f_elements[0] + f1_by_38 * f_elements[4] + f2_by_38 * f_elements[3];
    r[1] = two_times_f0 * f_elements[1] + f2_by_38 * f_elements[4] + f3_by_19 * f_elements[3];
    r[2] = two_times_f0 * f_elements[2] + f_elements[1] * f_elements[1] + f3_by_38 * f_elements[4];
    r[3] = two_times_f0 * f_elements[3] + two_times_f1 * f_elements[2] + f4_by_19 * f_elements[4];
    r[4] = two_times_f0 * f_elements[4] + two_times_f1 * f_elements[3] + f_elements[2] * f_elements[2];

   for(int j=0; j<5; j++) {
        uint64_t r_not_overflow = ((uint64_t) r[j]) & mask;
        carry = (uint64_t) (r[j] >> 51);
        if (j < 4) r[j+1] += carry;
        r[j] = r_not_overflow;
                
    }

    carry = r[0] >> 51;
    r[0] &= mask;
    r[1] += carry;
    r[1] &= mask;
    r[2] += carry;

    for(int k=0; k<5; k++){
        h[k] = r[k];
    }
}