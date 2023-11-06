void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    unsigned long long r[5];
    unsigned long long carry;
    unsigned long long f0,f1,f2,f3,f4,g0,g1,g2,g3,g4;
    unsigned long long f1_2, f2_2, f3_2, f4_2;
    unsigned long long u;

    f0 = f[0];
    f1 = f[1];
    f2 = f[2];
    f3 = f[3];
    f4 = f[4];

    g0 = g[0];
    g1 = g[1];
    g2 = g[2];
    g3 = g[3];
    g4 = g[4];

    f1_2 = 2 * f1;
    f2_2 = 2 * f2;
    f3_2 = 2 * f3;
    f4_2 = 2 * f4;

    r[0] = f0 * g0 + 19 * (  f1 * g4 + f2 * g3 + f3_2 * g2 + f4_2 * g1 );
    r[1] = f0 * g1 + f1 * g0 + 19 * (f2_2 * g4 + f3 * g3 + f4 * g2);
    r[2] = f0 * g2 + f1_2 * g1 + f2 * g0 + 19 * (  f3 * g4 + f4_2 * g3 );
    r[3] = f0 * g3 + f1_2 * g2 + f2_2 * g1 + f3 * g0 + 19 * f4 * g4;
    r[4] = f0 * g4 + f1_2 * g3 + f2_2 * g2 + f3_2 * g1 + f4 * g0;

    carry = r[0] >> 51; r[0] &= 0x7ffffffffffff; r[1] += carry;
    carry = r[1] >> 51; r[1] &= 0x7ffffffffffff; r[2] += carry;
    carry = r[2] >> 51; r[2] &= 0x7ffffffffffff; r[3] += carry;
    carry = r[3] >> 51; r[3] &= 0x7ffffffffffff; r[4] += carry;
    carry = r[4] >> 51; r[4] &= 0x7ffffffffffff; r[0] += 19 * carry;
    carry = r[0] >> 51; r[0] &= 0x7ffffffffffff; r[1] += carry;

    h[0] = r[0];
    h[1] = r[1];
    h[2] = r[2];
    h[3] = r[3];
    h[4] = r[4];
}