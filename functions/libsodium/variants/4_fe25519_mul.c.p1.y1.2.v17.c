variant 1:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  carry;

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

    uint128_t f1_19 = 19ULL * f1;
    uint128_t f2_19 = 19ULL * f2;
    uint128_t f3_19 = 19ULL * f3;
    uint128_t f4_19 = 19ULL * f4;

    r0 = f0 * g0 + f1_19 * g4 + f2_19 * g3 + f3_19 * g2 + f4_19 * g1;
    r1 = f0 * g1 +    f1 * g0 + f2_19 * g4 + f3_19 * g3 + f4_19 * g2;
    r2 = f0 * g2 +    f1 * g1 +    f2 * g0 + f3_19 * g4 + f4_19 * g3;
    r3 = f0 * g3 +    f1 * g2 +    f2 * g1 +    f3 * g0 + f4_19 * g4;
    r4 = f0 * g4 +    f1 * g3 +    f2 * g2 +    f3 * g1 +    f4 * g0;

    uint64_t r00 = ((uint64_t) r0) & mask;
    carry = (uint64_t) (r0 >> 51);
    r1 += carry;
    uint64_t r01 = ((uint64_t) r1) & mask;
    carry = (uint64_t) (r1 >> 51);
    r2 += carry;
    uint64_t r02 = ((uint64_t) r2) & mask;
    carry = (uint64_t) (r2 >> 51);
    r3 += carry;
    uint64_t r03 = ((uint64_t) r3) & mask;
    carry = (uint64_t) (r3 >> 51);
    r4 += carry;
    uint64_t r04 = ((uint64_t) r4) & mask;
    carry = (uint64_t) (r4 >> 51);
    r00 += 19ULL * carry;
    carry = r00 >> 51;
    r00 &= mask;
    r01 += carry;
    carry = r01 >> 51;
    r01 &= mask;
    r02 += carry;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}


variant 2:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t t_f[5];
    uint128_t t_g[5];
    uint64_t  carry;
    int i;

    for(i=0;i<5;i++)
    {
        t_f[i] = (uint128_t) f[i];
        t_g[i] = (uint128_t) g[i];
    } 

    uint128_t f1_19 = 19ULL * t_f[1];
    uint128_t f2_19 = 19ULL * t_f[2];
    uint128_t f3_19 = 19ULL * t_f[3];
    uint128_t f4_19 = 19ULL * t_f[4];

    r[0] = t_f[0] * t_g[0] + f1_19 * t_g[4] + f2_19 * t_g[3] + f3_19 * t_g[2] + f4_19 * t_g[1];
    r[1] = t_f[0] * t_g[1] + t_f[1] * t_g[0] + f2_19 * t_g[4] + f3_19 * t_g[3] + f4_19 * t_g[2];
    r[2] = t_f[0] * t_g[2] + t_f[1] * t_g[1] + t_f[2] * t_g[0] + f3_19 * t_g[4] + f4_19 * t_g[3];
    r[3] = t_f[0] * t_g[3] + t_f[1] * t_g[2] + t_f[2] * t_g[1] + t_f[3] * t_g[0] + f4_19 * t_g[4];
    r[4] = t_f[0] * t_g[4] + t_f[1] * t_g[3] + t_f[2] * t_g[2] + t_f[3] * t_g[1] + t_f[4] * t_g[0];

    for(i=0;i<5;i++)
    {
        h[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[(i+1)%5]    += carry;
        h[i]    = h[i] & mask;
        carry  = h[i] >> 51;
        h[(i+1)%5]   += carry;
    }  
}

