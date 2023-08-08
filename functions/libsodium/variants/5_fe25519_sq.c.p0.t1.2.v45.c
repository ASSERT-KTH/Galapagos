fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_copy[5];
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r0[5];
    uint64_t  carry;

    for(int i = 0; i < 5; ++i) {
        f_copy[i] = (uint128_t) f[i];
    }

    f0_2 = f_copy[0] << 1;
    f1_2 = f_copy[1] << 1;

    f1_38 = 38ULL * f_copy[1];
    f2_38 = 38ULL * f_copy[2];
    f3_38 = 38ULL * f_copy[3];

    f3_19 = 19ULL * f_copy[3];
    f4_19 = 19ULL * f_copy[4];

    r[0] =    f_copy[0] * f_copy[0] + f1_38 * f_copy[4] + f2_38 * f_copy[3];
    r[1] = f0_2 * f_copy[1] + f2_38 * f_copy[4] + f3_19 * f_copy[3];
    r[2] = f0_2 * f_copy[2] + f_copy[1] * f_copy[1] + f3_38 * f_copy[4];
    r[3] = f0_2 * f_copy[3] + f1_2 * f_copy[2] + f4_19 * f_copy[4];
    r[4] = f0_2 * f_copy[4] + f1_2 * f_copy[3] + f_copy[2] * f_copy[2];

    for(int i = 0; i < 5; ++i) {
        r0[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        r[(i + 1) % 5] += carry;
        r0[(i + 1) % 5] = ((uint64_t) r[(i + 1) % 5]) & mask;
        carry = (uint64_t) (r[(i + 1) % 5] >> 51);
        r0[i] += carry;
        r0[i] &= mask;

    }

    for(int i = 0; i < 5; ++i) {
        h[i] = r0[i];
    }
}