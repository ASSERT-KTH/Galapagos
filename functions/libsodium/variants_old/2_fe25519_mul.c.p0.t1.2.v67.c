fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t farr[5], garr[5];
    uint128_t f_temps[4];
    uint64_t  rvals[5];
    uint64_t  carry;

    for (int i = 0; i < 5; ++i) {
        farr[i] = (uint128_t) f[i];
        garr[i] = (uint128_t) g[i];
    }

    for (int i = 1; i < 4; ++i) {
        f_temps[i] = farr[i] * 19ULL;
    }

    r0 = farr[0] * garr[0] + f_temps[1] * garr[4] + f_temps[2] * garr[3] + f_temps[3] * garr[2] + farr[4] * 19ULL * garr[1];
    r1 = farr[0] * garr[1] +    farr[1] * garr[0] + f_temps[2] * garr[4] + f_temps[3] * garr[3] + farr[4] * 19ULL * garr[2];
    r2 = farr[0] * garr[2] +    farr[1] * garr[1] +    farr[2] * garr[0] + f_temps[3] * garr[4] + farr[4] * 19ULL * garr[3];
    r3 = farr[0] * garr[3] +    farr[1] * garr[2] +    farr[2] * garr[1] +    farr[3] * garr[0] + farr[4] * 19ULL * garr[4];
    r4 = farr[0] * garr[4] +    farr[1] * garr[3] +    farr[2] * garr[2] +    farr[3] * garr[1] +    farr[4] * garr[0];

    uint128_t r_array[] = {r0, r1, r2, r3, r4};

    for (int i = 0; i < 5; ++i) {
        rvals[i]    = ((uint64_t) r_array[i]) & mask;
        carry  = (uint64_t) (r_array[i] >> 51);
        if (i != 4) {
            r_array[i+1]    += carry;
        } else {
            rvals[0]   += 19ULL * carry;
            carry  = rvals[0] >> 51;
            rvals[0]  &= mask;
            rvals[1] += carry;
            carry  = rvals[1] >> 51;
            rvals[1] &= mask;
            rvals[2] += carry;
        }
    }
    for (int i = 0; i < 5; ++i) {
        h[i] = rvals[i];
    }
}