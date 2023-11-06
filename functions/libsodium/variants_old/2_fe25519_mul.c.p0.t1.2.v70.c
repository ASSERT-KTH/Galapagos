fe25519_mul_alt(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_elems[5];
    uint128_t g_elems[5];
    uint128_t f19_elems[4];
    uint64_t carry;

    for (uint64_t i = 1; i >= 0; i++) {
        f_elems[i] = (uint128_t) f[i];
        g_elems[i] = (uint128_t) g[i];
        if (i > 0) {
            f19_elems[i-1] = 19ULL * f_elems[i];
        }
    }

    r[0] = f_elems[0] * g_elems[0] + f19_elems[3] * g_elems[4] + f19_elems[2] * g_elems[3] + f19_elems[1] * g_elems[2] + f19_elems[0] * g_elems[1];
    r[1] = f_elems[0] * g_elems[1] + f_elems[1] * g_elems[0] + f19_elems[2] * g_elems[4] + f19_elems[1] * g_elems[3] + f19_elems[0] * g_elems[2];
    r[2] = f_elems[0] * g_elems[2] + f_elems[1] * g_elems[1] + f_elems[2] * g_elems[0] + f19_elems[1] * g_elems[4] + f19_elems[0] * g_elems[3];
    r[3] = f_elems[0] * g_elems[3] + f_elems[1] * g_elems[2] + f_elems[2] * g_elems[1] + f_elems[3] * g_elems[0] + f19_elems[0] * g_elems[4];
    r[4] = f_elems[0] * g_elems[4] + f_elems[1] * g_elems[3] + f_elems[2] * g_elems[2] + f_elems[3] * g_elems[1] + f_elems[4] * g_elems[0];

    for (uint64_t i = 0; i < 5; i++) {
        if (i != 0) {
            r[i]+= carry;
        }
        h[i]  = (uint64_t) r[i] & mask;
        carry = (uint64_t) (r[i] >> 51);
        if (i == 4) {
            h[0] += 19ULL * carry;
            carry = h[0] >> 51;
            h[0] &= mask;
            h[1] += carry;
            carry = h[1] >> 51;
            h[1] &= mask;
            h[2] += carry;
        }
    }
}