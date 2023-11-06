fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    const uint128_t nineteen = 19ULL;
    uint128_t r[5], f_mul[5], f_mul_nineteen[4], g_mul[5];
    uint64_t  res[5], carry;

    for (int i = 0; i < 5; i++) {
        f_mul[i] = (uint128_t) f[i];
        g_mul[i] = (uint128_t) g[i];
    }

    for (int i = 1; i < 5; i++) {
        f_mul_nineteen[i - 1] = nineteen * f_mul[i];
    }

    r[0] = f_mul[0] * g_mul[0] + f_mul_nineteen[3] * g_mul[4] + f_mul_nineteen[2] * g_mul[3] + f_mul_nineteen[1] * g_mul[2] + f_mul_nineteen[0] * g_mul[1];
    r[1] = f_mul[0] * g_mul[1] + f_mul[1] * g_mul[0] + f_mul_nineteen[2] * g_mul[4] + f_mul_nineteen[1] * g_mul[3] + f_mul_nineteen[0] * g_mul[2];
    r[2] = f_mul[0] * g_mul[2] + f_mul[1] * g_mul[1] + f_mul[2] * g_mul[0] + f_mul_nineteen[1] * g_mul[4] + f_mul_nineteen[0] * g_mul[3];
    r[3] = f_mul[0] * g_mul[3] + f_mul[1] * g_mul[2] + f_mul[2] * g_mul[1] + f_mul[3] * g_mul[0] + f_mul_nineteen[0] * g_mul[4];
    r[4] = f_mul[0] * g_mul[4] + f_mul[1] * g_mul[3] + f_mul[2] * g_mul[2] + f_mul[3] * g_mul[1] + f_mul[4] * g_mul[0];

    for (int i = 0; i < 5; i++) {
        res[i] = ((uint64_t)r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        
        if (i < 4)
            r[i + 1] += carry;
        else
            res[0] += nineteen * carry;
    }

    for (int i = 0; i < 3; i++) {
        carry = (i == 2) ? 0ULL : (res[i + 1] >> 51);
        res[i] &= mask;
        res[i + 1] = (carry == 0ULL) ? res[i + 1] : res[i + 1] + carry;
    }

    for (int i = 0; i < 5; i++) {
        h[i] = res[i];
    }
}