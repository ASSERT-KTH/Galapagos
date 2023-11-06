fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], r_count[5];
    uint128_t f_values[5], g_values[5];
    uint128_t f_factors[5];
    uint64_t  carry;
    int i;

    for (i = 0; i < 5; i++) {
        f_values[i] = (uint128_t) f[i];
        g_values[i] = (uint128_t) g[i];

        if (i != 0) {
            f_factors[i] = 19ULL * f_values[i];
        }
    }

    r[0] = f_values[0] * g_values[0] + f_factors[1] * g_values[4] + f_factors[2] * g_values[3] + f_factors[3] * g_values[2] + f_factors[4] * g_values[1];
    r[1] = f_values[0] * g_values[1] + f_values[1] * g_values[0] + f_factors[2] * g_values[4] + f_factors[3] * g_values[3] + f_factors[4] * g_values[2];
    r[2] = f_values[0] * g_values[2] + f_values[1] * g_values[1] + f_values[2] * g_values[0] + f_factors[3] * g_values[4] + f_factors[4] * g_values[3];
    r[3] = f_values[0] * g_values[3] + f_values[1] * g_values[2] + f_values[2] * g_values[1] + f_values[3] * g_values[0] + f_factors[4] * g_values[4];
    r[4] = f_values[0] * g_values[4] + f_values[1] * g_values[3] + f_values[2] * g_values[2] + f_values[3] * g_values[1] + f_values[4] * g_values[0];

    for (i = 0; i < 5; i++) {
        r_count[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        if (i != 4) {
            r[i + 1] += carry;
        }
    }

    r_count[0] += 19ULL * carry;
    carry = r_count[0] >> 51;
    r_count[0] &= mask;
    r_count[1] += carry;
    carry = r_count[1] >> 51;
    r_count[1] &= mask;
    r_count[2] += carry;

    for (i = 0; i < 5; i++) {
        h[i] = r_count[i];
    }
}