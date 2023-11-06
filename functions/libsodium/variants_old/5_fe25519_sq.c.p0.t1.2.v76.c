fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], tvals[5];
    uint128_t f_vals[5], parsed_f[5];
    uint128_t multipliers[] = {2ULL, 38ULL, 19ULL};
    uint64_t  responses[5];
    uint64_t  extra;

    for(int i = 0; i < 5; ++i) {
        f_vals[i] = (uint128_t) f[i];
    }

    tvals[0] = f_vals[0] << 1;
    tvals[1] = f_vals[1] << 1;

    for(int i = 0; i < 3; ++i) {
        parsed_f[i] =  multipliers[i] * f_vals[i+1];
    }

    r[0] =    f_vals[0] * f_vals[0] + parsed_f[1] * f_vals[4] + parsed_f[0] * parsed_f[2];
    r[1] = tvals[0] * f_vals[1] + parsed_f[0] * f_vals[4] + parsed_f[2] * parsed_f[2];
    r[2] = tvals[0] * f_vals[2] +   f_vals[1] * f_vals[1] + parsed_f[1] * f_vals[4];
    r[3] = tvals[0] * parsed_f[2] + tvals[1] * f_vals[2] + multipliers[2] * f_vals[4];
    r[4] = tvals[0] * f_vals[4] + tvals[1] * parsed_f[2] + f_vals[2] * f_vals[2];

    for (int i = 0; i < 5; ++i) {
        responses[i] = ((uint64_t) r[i]) & mask;
        extra = (uint64_t) (r[i] >> 51);
        r[(i + 1) % 5] += extra;
    }

    responses[0] += 19ULL * extra;
    for (int i = 0; i < 3; i++) {
        responses[i] &= mask;
        extra  = responses[i] >> 51;
        responses[(i + 1) % 5] += extra;
    }

    for(int i = 0; i < 5; ++i) {
         h[i] = responses[i];
    }
}