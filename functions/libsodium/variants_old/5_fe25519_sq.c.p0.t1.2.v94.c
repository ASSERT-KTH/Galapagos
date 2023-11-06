fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t ff[5];
    uint128_t f_x2[2], f_x38[3], f_x19[2];
    uint64_t  r[5];
    uint64_t  carry_result;

    for (int i = 0; i < 5; i++)
        ff[i] = (uint128_t) f[i];
    
    f_x2[0] = ff[0] << 1;
    f_x2[1] = ff[1] << 1;

    for (int i = 0; i < 3; i++)
        f_x38[i] = 38ULL * ff[i + 1];

    for (int i = 0; i < 2; i++)
        f_x19[i] = 19ULL * ff[i + 3];

    r[0] =   ff[0] * ff[0] + f_x38[0] * ff[4] + f_x38[1] * ff[3];
    r[1] = f_x2[0] * ff[1] + f_x38[1] * ff[4] + f_x19[0] * ff[3];
    r[2] = f_x2[0] * ff[2] +    ff[1] * ff[1] + f_x38[2] * ff[4];
    r[3] = f_x2[0] * ff[3] +  f_x2[1] * ff[2] + f_x19[1] * ff[4];
    r[4] = f_x2[0] * ff[4] +  f_x2[1] * ff[3] +    ff[2] * ff[2];

    for (int i = 0; i < 5; i++) {
        r[i]    = ((uint64_t) r[i]) & mask;
        carry_result  = (uint64_t) (r[i] >> 51);
        r[(i + 1) % 5] += carry_result;
    }

    for (int i = 0; i < 5; i++) {
        r[i] += 19ULL * ((uint64_t) (r[4] >> 51)); // propagate final carry to all
        r[i]  &= mask; // apply mask

        // boundary carry handling
        if (r[i] >> 51) {
            r[(i + 1) % 5] += r[i] >> 51;
            r[i] &= mask;
        }
    }

    for(int i = 0; i < 5; i++)
        h[i] = r[i];
}
