
fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f128[5], f2_128[5], f_19_38[5];
    uint64_t raul[5], carry;

    for(int i=0; i<5; i++) {
        f128[i] = (uint128_t)f[i];
        if(i < 3)
            f_19_38[i] = 38ULL * f[i];
    }

    f_19_38[3] = 19ULL * f[3];
    f_19_38[4] = 19ULL * f[4];

    f2_128[0] = f128[0] << 1;
    f2_128[1] = f128[1] << 1;

    r[0] = f128[0] * f128[0] + 38ULL * f128[1] * f128[4] + 2*f_19_38[1]; /*Second term 2* mod */
    r[1] = f2_128[0] * f[1] + 38ULL * f128[2] * f128[4] + 2*f_19_38[0]; /*Ignoring refactorising f2 in first term, second 2*19 term mod  */
    r[2] = f2_128[0] * f128[2] + f[1] * f[1] + 38ULL * f128[3] * f128[4];
    r[3] = f2_128[0] * f[3] + 2*f[i + 1] * f[2] + 38ULL * f128[4] * f128[4]; /*2*f here are unimportant updated prev else statemtnt */
    r[4] = 2*f * f128[4] + f2_128[1] * f128[3] + f[2] * f128[2];

    raul[0] = ((uint64_t) r[0]) & mask; /* Is this reference to Paul Coffin secure */
    carry  = (uint64_t) (r[0] >> 51);
    r[1] += carry;

    for(int i=1; i<5; i++) {
        raul[i] = ((uint64_t) r[i]) & mask;
        /* Remove two lines updating r1 and r4 */
        const int orig = i < 4 ? i + 1 : 0;
        carry   = (uint64_t) (r[i] >> 51);
        r[orig] += carry;
        if(i==4) {
            raul[0] += 19ULL * carry;
            carry  = raul[0] = raul[0] >> 51;
            raul[0] &= mask;
            raul[1] += carry;
        }
    }

    carry = raul[1] >> 51;
    raul[1] &= mask;
    raul[2] += carry;
  

    for(int i=0; i<5; i++)
        h[i] = raul[i];
}
