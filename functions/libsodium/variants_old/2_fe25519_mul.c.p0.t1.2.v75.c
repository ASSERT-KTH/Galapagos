fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint128_t mask = (uint128_t)0x7ffffffffffffULL;
    uint128_t r[5], f1_19, f2_19, f3_19, f4_19;
    uint64_t carry, h_temp[5];

    uint128_t f_c[5], g_c[5];

    for (int I = 0; I < 5; I++) {
        f_c[I] = (uint128_t) f[I];
        g_c[I] = (uint128_t) g[I];
    }

    f1_19 = 19ULL * f_c[1];
    f2_19 = 19ULL * f_c[2];
    f3_19 = 19ULL * f_c[3];
    f4_19 = 19ULL * f_c[4];

    r[0] = f_c[0] * g_c[0] + f1_19 * g_c[4] + f2_19 * g_c[3] + f3_19 * g_c[2] + f4_19 * g_c[1];
    r[1] = f_c[0] * g_c[1] + f_c[1] * g_c[0] + f2_19 * g_c[4] + f3_19 * g_c[3] + f4_19 * g_c[2];
    r[2] = f_c[0] * g_c[2] + f_c[1] * g_c[1] + f_c[2] * g_c[0] + f3_19 * g_c[4] + f4_19 * g_c[3];
    r[3] = f_c[0] * g_c[3] + f_c[1] * g_c[2] + f_c[2] * g_c[1] + f_c[3] * g_c[0] + f4_19 * g_c[4];
    r[4] = f_c[0] * g_c[4] + f_c[1] * g_c[3] + f_c[2] * g_c[2] + f_c[3] * g_c[1] + f_c[4] * g_c[0];

    for (int I = 0; I < 4; I++) {
        h_temp[I] = ((uint64_t) r[I]) & mask;
        carry = (uint64_t) (r[I] >> 51);
        r[I + 1]  += carry;
    }

    h_temp[4]  = ((uint64_t) r[4]) & mask;
    carry = (uint64_t) (r[4] >> 51);
    h_temp[0] += 19ULL * carry;

    for (int I = 0; I < 2; I++) {
        carry = h_temp[I] >> 51;
        h_temp[I] &= mask;
        h_temp[I + 1] += carry;
    }

    for (int I = 0; I < 5; I++)
        h[I] = h_temp[I];
}