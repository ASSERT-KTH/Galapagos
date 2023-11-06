fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    int64_t r0, r1, r2, r3, r4;
    int64_t f0, f1, f2, f3, f4;
    int64_t f1_2, f2_2, f3_2, f4_2;
    int64_t g0, g1, g2, g3, g4;
    int64_t carry, carry1, carry2, carry3, carry4;

    f0 = f[0];
    f1 = f[1];
    f2 = f[2];
    f3 = f[3];
    f4 = f[4];

    f1_2 = 19LL * f1;
    f2_2 = 19LL * f2;
    f3_2 = 19LL * f3;
    f4_2 = 19LL * f4;

    g0 = g[0];
    g1 = g[1];
    g2 = g[2];
    g3 = g[3];
    g4 = g[4];

    r0 = f0 * g0 + f1_2 * g4 + f2_2 * g3 + f3_2 * g2 + f4_2 * g1;
    r1 = f0 * g1 + f1 * g0 + f2_2 * g4 + f3_2 * g3 + f4_2 * g2;
    r2 = f0 * g2 + f1 * g1 + f2 * g0 + f3_2 * g4 + f4_2 * g3;
    r3 = f0 * g3 + f1 * g2 + f2 * g1 + f3 * g0 + f4_2 * g4;
    r4 = f0 * g4 + f1 * g3 + f2 * g2 + f3 * g1 + f4 * g0;

    carry = r0 >> 51; r0 &= mask;
    r1 += carry; carry = r1 >> 51; r1 &= mask;
    r2 += carry; carry = r2 >> 51; r2 &= mask;
    r3 += carry; carry = r3 >> 51; r3 &= mask;
    r4 += carry; carry = r4 >> 51; r4 &= mask;

    r0 = r0 + 19LL * carry;

    carry1 = r0 >> 51; r0 &= mask; r1 += carry1; carry2 = r1 >> 51; r1 &= mask;
    r2 += carry2; carry3 = r2 >> 51; r2 &= mask; r3 += carry3; carry4 = r3 >> 51;
    r3 &= mask; r4 += carry4;

    h[0] = r0;
    h[1] = r1;
    h[2] = r2;
    h[3] = r3;
    h[4] = r4;
}