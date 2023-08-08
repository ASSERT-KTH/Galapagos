fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f_[5];
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r[5];
    uint64_t  carry;

    f_[0] = (uint128_t) f[0];
    f_[1] = (uint128_t) f[1];
    f_[2] = (uint128_t) f[2];
    f_[3] = (uint128_t) f[3];
    f_[4] = (uint128_t) f[4];

    f0_2 = f_[0] << 1;
    f1_2 = f_[1] << 1;

    f1_38 = 38ULL * f_[1];
    f2_38 = 38ULL * f_[2];
    f3_38 = 38ULL * f_[3];

    f3_19 = 19ULL * f_[3];
    f4_19 = 19ULL * f_[4];

    r[0] =   f_[0] * f_[0] + f1_38 * f_[4] + f2_38 * f_[3];
    r[1] = f0_2 * f_[1] + f2_38 * f_[4] + f3_19 * f_[3];
    r[2] = f0_2 * f_[2] +    f_[1] * f_[1] + f3_38 * f_[4];
    r[3] = f0_2 * f_[3] +  f1_2 * f_[2] + f4_19 * f_[4];
    r[4] = f0_2 * f_[4] +  f1_2 * f_[3] +    f_[2] * f_[2];

    for (int i = 0; i < 5; i++) {
        r[i]    = (r[i] % mask);
        carry  = (uint64_t) (r[i] / pow(2, 51));
        r[(i+1)%5] += carry;
        r[i+1%5] += 19ULL * carry;
        carry  = r[i+1%5] / pow(2, 51);
        r[i+1%5] &= mask;
        r[(i+2)%5] += carry;
    }

    h[0] = r[0];
    h[1] = r[1];
    h[2] = r[2];
    h[3] = r[3];
    h[4] = r[4];
}