Here fixed types replaced with signed integers and filled in bits that were stripped out whilst performing bitwise shifting operations to optimise code functionality.  


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    signed long long int mask = 0x7ffffffffffffULL;
    signed long long int r0, r1, r2, r3, r4;
    signed long long int f0, f1, f2, f3, f4;
    signed long long int g0, g1, g2, g3, g4;
    signed long long int r00, r01, r02, r03, r04;
    signed long long int carry, f1_19, f2_19, f3_19, f4_19;

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

    f1_19 = 19 * f1;
    f2_19 = 19 * f2;
    f3_19 = 19 * f3;
    f4_19 = 19 * f4;

    r0 = f0 * g0 + f1_19 * g4 + f2_19 * g3 + f3_19 * g2 + f4_19 * g1;
    r1 = f0 * g1 + f1    * g0 + f2_19 * g4 + f3_19 * g3 + f4_19 * g2;
    r2 = f0 * g2 + f1    * g1 + f2    * g0 + f3_19 * g4 + f4_19 * g3;
    r3 = f0 * g3 + f1    * g2 + f2    * g1 + f3    * g0 + f4_19 * g4;
    r4 = f0 * g4 + f1    * g3 + f2    * g2 + f3    * g1 + f4    * g0;

    carry  = r0 >> 51;
    r0 &= mask;
    r1 += carry;
    carry  = r1 >> 51;
    r1 &= mask;
    r2 += carry;
    carry  = r2 >> 51;
    r2 &= mask;
    r3 += carry;
    carry  = r3 >> 51;
    r3 &= mask;
    r4 += carry;
    carry  = r4 >> 51;
    r4 &= mask;
    r0 += 19 * carry;
    carry  = r0 >> 51;
    r0 &= mask;
    r1 += carry;
    carry  = r1 >> 51;
    r1 &= mask;
    r2 += carry;

    h[0] = r0;
    h[1] = r1;
    h[2] = r2;
    h[3] = r3;
    h[4] = r4;
}
