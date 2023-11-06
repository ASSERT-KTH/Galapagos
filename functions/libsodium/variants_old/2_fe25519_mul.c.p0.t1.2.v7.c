fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], t;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t g0, g1, g2, g3, g4;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    g0 = (uint128_t) g[0];
    g1 = (uint128_t) g[1];
    g2 = (uint128_t) g[2];
    g3 = (uint128_t) g[3];
    g4 = (uint128_t) g[4];

    t = 19ULL * f1 ; r[0] = f0 * g0 + t * g4;
    r[1] = f0 * g1 + g0 * f1;
    t = 19ULL * f2 ; r[0] += t * g3 ; r[1] += t * g4;
    r[2] = f0 * g2 + g1 * f1 + g0 * f2;
    t = 19ULL * f3 ; r[0] += t * g2 ; r[1] += t * g3 ; r[2] += t * g4;
    r[3] = f0 * g3 + g2 * f1 + g1 * f2 + g0 * f3;
    t = 19ULL * f4 ; r[0] += t * g1 ; r[1] += t * g2 ; r[2] += t * g3 ; r[3] += t * g4;
    r[4] = f0 * g4 + g3 * f1 + g2 * f2 + g1 * f3 + g0 * f4;

    uint64_t  carry = 0;
    for (int i = 0; i < 5; i++) {
        carry = (uint64_t) (r[i] >> 51);
        if (i<4)
            r[i+1] += carry ;
        else {
            r[0]+=19ULL * carry;
            carry  = (r[0] >> 51);
            r[0] &= mask;
        }
        r[i] &= mask;
    }

    h[0] = r[0];
    h[1] = r[1];
    h[2] = r[2];
    h[3] = r[3];
    h[4] = r[4];
}