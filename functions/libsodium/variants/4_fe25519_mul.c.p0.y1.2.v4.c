void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffff;
    uint64_t carry;
    uint128_t  f1_19, f2_19, f3_19, f4_19;
    uint128_t  r0, r1, r2, r3, r4;

    uint128_t  f_values[5] = {(uint128_t) f[0], (uint128_t) f[1], (uint128_t) f[2], (uint128_t) f[3], (uint128_t) f[4]};
    uint128_t  g_values[5] = {(uint128_t) g[0], (uint128_t) g[1], (uint128_t) g[2], (uint128_t) g[3], (uint128_t) g[4]};

    f1_19 = 19 * f_values[1];
    f2_19 = 19 * f_values[2];
    f3_19 = 19 * f_values[3];
    f4_19 = 19 * f_values[4];

    r0 = f_values[0] * g_values[0] + f1_19 * g_values[4] + f2_19 * g_values[3] + f3_19 * g_values[2] + f4_19 * g_values[1];
    r1 = f_values[0] * g_values[1] + f_values[1] * g_values[0] + f2_19 * g_values[4] + f3_19 * g_values[3] + f4_19 * g_values[2];
    r2 = f_values[0] * g_values[2] + f_values[1] * g_values[1] + f_values[2] * g_values[0] + f3_19 * g_values[4] + f4_19 * g_values[3];
    r3 = f_values[0] * g_values[3] + f_values[1] * g_values[2] + f_values[2] * g_values[1] + f_values[3] * g_values[0] + f4_19 * g_values[4];
    r4 = f_values[0] * g_values[4] + f_values[1] * g_values[3] + f_values[2] * g_values[2] + f_values[3] * g_values[1] + f_values[4] * g_values[0];

    for (int i=0; i<=4; i++) {
        uint128_t * r_values = &r0;
        uint64_t r_lo = ((uint64_t) r_values[i]) & mask;
        carry = (uint64_t)(r_values[i] >> 51);
        if (i < 4) r_values[i+1] += carry;
        if (i == 4) r0  += 19 * carry;
        carry = r_values[0] >> 51; r_values[0] &= mask;
        r_values[1] += carry;
        carry = r_values[1] >> 51; r_values[1] &= mask;
        r_values[2] += carry;
        h[i] = r_lo;
    }
}