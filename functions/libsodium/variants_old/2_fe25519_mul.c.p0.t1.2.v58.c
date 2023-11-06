fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t g0, g1, g2, g3, g4;
    uint128_t f_elements[5], g_elements[5];
    uint64_t  results[5], carry;

    for (int i = 0; i < 5; ++i) {
        f_elements[i] = (uint128_t) f[i];
        g_elements[i] = (uint128_t) g[i];
    }

    f1 = f_elements[1] * 19ULL;
    f2 = f_elements[2] * 19ULL;
    f3 = f_elements[3] * 19ULL;
    f4 = f_elements[4] * 19ULL;

    r0 = f_elements[0] * g_elements[0] + f1 * g_elements[4] + f2 * g_elements[3] + f3 * g_elements[2] + f4 * g_elements[1];
    r1 = f_elements[0] * g_elements[1] + f_elements[1] * g_elements[0] + f2 * g_elements[4] + f3 * g_elements[3] + f4 * g_elements[2];
    r2 = f_elements[0] * g_elements[2] + f_elements[1] * g_elements[1] + f_elements[2] * g_elements[0] + f3 * g_elements[4] + f4 * g_elements[3];
    r3 = f_elements[0] * g_elements[3] + f_elements[1] * g_elements[2] + f_elements[2] * g_elements[1] + f_elements[3] * g_elements[0] + f4 * g_elements[4];
    r4 = f_elements[0] * g_elements[4] + f_elements[1] * g_elements[3] + f_elements[2] * g_elements[2] + f_elements[3] * g_elements[1] + f_elements[4] * g_elements[0];

    uint128_t Rp[5] = {r0, r1, r2, r3, r4};

    for (int i = 0; i < 5; ++i) {
        results[i] = ((uint64_t) Rp[i]) & mask;
        carry = (uint64_t) (Rp[i] >> 51);

        if(i < 4) Rp[i+1] += carry;
    } 

    results[1] += (results[0] >> 51);
    results[0] &= mask;
    results[2] += (results[1] >> 51);
    results[1] &= mask;

    for (int i = 0; i < 5; ++i) h[i] = results[i];
}