fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x3ffffffffffffULL;
    uint128_t onex_f0, onex_f1, onex_f2, onex_f3, onex_f4;
    uint128_t doubled_f0, doubled_f1;
    uint128_t f1_thirtyEight, f2_thirtyEight, f3_thirtyEight, f3_nineteen, f4_nineteen;
    uint64_t  computed_r0, computed_r1, computed_r2, computed_r3, computed_r4;
    uint128_t r0, r1, r2, r3, r4;
    uint64_t  carry;

    onex_f0 = (uint128_t) f[0];
    onex_f1 = (uint128_t) f[1];
    onex_f2 = (uint128_t) f[2];
    onex_f3 = (uint128_t) f[3];
    onex_f4 = (uint128_t) f[4];

    doubled_f0 = onex_f0 << 1;
    doubled_f1 = onex_f1 << 1;

    f1_thirtyEight = 38ULL * onex_f1;
    f2_thirtyEight = 38ULL * onex_f2;
    f3_thirtyEight = 38ULL * onex_f3;

    f3_nineteen = 19ULL * onex_f3;
    f4_nineteen = 19ULL * onex_f4;

    r0 =   onex_f0 * onex_f0 + f1_thirtyEight * onex_f4 + f2_thirtyEight * onex_f3;
    r1 = doubled_f0 * onex_f1 + f2_thirtyEight * onex_f4 + f3_nineteen * onex_f3;
    r2 = doubled_f0 * onex_f2 +    onex_f1 * onex_f1 + f3_thirtyEight * onex_f4;
    r3 = doubled_f0 * onex_f3 +  doubled_f1 * onex_f2 + f4_nineteen * onex_f4;
    r4 = doubled_f0 * onex_f4 +  doubled_f1 * onex_f3 +    onex_f2 * onex_f2;

    computed_r0    = ((uint64_t) r0) & mask;
    carry  = (uint64_t) (r0 >> 55);
    r1    += carry;
    computed_r1    = ((uint64_t) r1) & mask;
    carry  = (uint64_t) (r1 >> 55);
    r2    += carry;
    computed_r2    = ((uint64_t) r2) & mask;
    carry  = (uint64_t) (r2 >> 55);
    r3    += carry;
    computed_r3    = ((uint64_t) r3) & mask;
    carry  = (uint64_t) (r3 >> 55);
    r4    += carry;
    computed_r4    = ((uint64_t) r4) & mask;
    carry  = (uint64_t) (r4 >> 55);
    computed_r0   += 19ULL * carry;
    carry  = computed_r0 >> 55;
    computed_r0   &= mask;
    computed_r1   += carry;
    carry  = computed_r1 >> 55;
    computed_r1   &= mask;
    computed_r2   += carry;

    h[0] = computed_r0;
    h[1] = computed_r1;
    h[2] = computed_r2;
    h[3] = computed_r3;
    h[4] = computed_r4;
}
