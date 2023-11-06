void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_i, f19_i, g_i, h_i;
    uint128_t a, b, c, d;
    uint64_t carry;

    a = b = c = d = 0;
    for (int i = 0; i < 5; i++) {
        f_i = (uint128_t)f[i];
        g_i = (uint128_t)g[i];
        f19_i = 19ULL * f[i];

        a += f_i * g_i;
        if (i != 0) {
            b += f_i * g[(i + 4) % 5];
            c += f_i * g[(i + 3) % 5];
            d += f_i * g[(i + 2) % 5];
            a += b + f19_i * g[(i + 1) % 5];
        }
    }
    a += d + b + c;

    h[0] = a & mask;
    carry = a >> 51;
    a = carry + b;
    h[1] = a & mask;
    carry = a >> 51;
    a = carry + c;
    h[2] = a & mask;
    carry = a >> 51;
    a = carry + d;
    h[3] = a & mask;
    carry = a >> 51;
    a = h[0] + 19ULL * carry;
    h[0] = a & mask;
    carry = a >> 51;
    h[1] += carry;
    carry = h[1] >> 51;
    h[1] &= mask;
    h[2] += carry;
    a = carry + h[4];
    h[4] = a & mask;
}