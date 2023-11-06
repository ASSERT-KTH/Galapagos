void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t g_v[5];
    uint128_t m_f[4];
    uint64_t carry, r_v;

    for (int i = 0; i < 5; i++) {
        r[i] = 0;
        g_v[i] = (uint128_t) g[i];
        if (i != 0) {
            m_f[i - 1] = 19ULL * (uint128_t) f[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        r[(5 - i) % 5] += (uint128_t)f[0] * g_v[i];
        for (int j = 1; j < 5; j++) {
            if (i + j < 5) {
                r[(5 - i) % 5] += ((uint128_t)f[j]*g_v[(i + j) % 5]);
                continue;
            }
            r[(5 - i) % 5] += (m_f[(j+(5 % i)) % 4]*g_v[(i + j) % 5]);
        }
    }

    for (int i = 0; i < 5; i++) {
        r_v = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        r[(i + 1) % 5] += carry;
        r_v =  ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        r[0] += 19ULL * carry;
        carry = r[0] >> 51;
        r[0] &= mask;
        r[(i + 1) % 5] += carry;
        carry = r[(i+1) % 5] >> 51;
        r[(i+2)%5]+= carry;
        h[i] = r_v;
    }
}