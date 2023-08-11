fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_n[5], g_n[5];
    uint128_t f19[4];
    uint64_t r_5[5], carry;

    for (int i = 0; i < 5; i++) {
        f_n[i] = (uint128_t) f[i];
    }

    for (int i = 0; i < 5; i++) {
        g_n[i] = (uint128_t) g[i];
    }

    for (int i = 1; i < 5; i++) {
        f19[i-1] = 19ULL * f_n[i];
    }

    r[0] = f_n[0] * g_n[0] + f19[0] * g_n[4] + f19[1] * g_n[3] + f19[2] * g_n[2] + f19[3] * g_n[1];
    r[1] = f_n[0] * g_n[1] + f_n[1] * g_n[0] + f19[1] * g_n[4] + f19[2] * g_n[3] + f19[3] * g_n[2];
    r[2] = f_n[0] * g_n[2] + f_n[1] * g_n[1] + f_n[2] * g_n[0] + f19[2] * g_n[4] + f19[3] * g_n[3];
    r[3] = f_n[0] * g_n[3] + f_n[1] * g_n[2] + f_n[2] * g_n[1] + f_n[3] * g_n[0] + f19[3] * g_n[4];
    r[4] = f_n[0] * g_n[4] + f_n[1] * g_n[3] + f_n[2] * g_n[2] + f_n[3] * g_n[1] + f_n[4] * g_n[0];

    for (size_t i = 0; i < 5; ++i){
        r_5[i] = ((uint64_t) r[i]) & mask;
        if(i == 4)
            carry  = (uint64_t) (r[4] >> 51);
        else {
            carry = (uint64_t) (r[i] >> 51);
            r[i+1] += carry;
        }

    }

    constexpr uint64_t carryMask = 19ULL;
    r_5[0] += carryMask * carry;
    carry  = r_5[0] >> 51;
    r_5[0] &= mask;
    r_5[1] += carry;

    for (int i = 0; i < 5; i++) {
        h[i] = r_5[i];
    }
}