Here is a transformed function that fully preserves the original version functionality with altered calculation order and refac changes:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t  mask = 0x7ffffffffffffULL;
    uint64_t  carry;    
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t g0, g1, g2, g3, g4;
    uint128_t f1_19, f2_19, f3_19, f4_19;

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

    f1_19 = 19ULL * f1; 
    f2_19 = 19ULL * f2; 
    f3_19 = 19ULL * f3; 
    f4_19 = 19ULL * f4;

    r0 = f0*g0 + f1_19*g4 + f2_19*g3 + f3_19*g2 + f4_19*g1;
    r1 = f0*g1 + f1*g0 + f2_19*g4 + f3_19*g3 + f4_19*g2;
    r2 = f0*g2 + f1*g1 + f2*g0 + f3_19*g4 + f4_19*g3;
    r3 = f0*g3 + f1*g2 + f2*g1 + f3*g0 + f4_19*g4;
    r4 = f0*g4 + f1*g3 + f2*g2 + f3*g1 + f4*g0;

    h[0] = r0 = r0 & mask + 19ULL*((carry = r0 >> 51)); 
    h[1] = r1 = (r1 + carry) & mask + ((carry = (r1 + carry) >> 51) > 0 ? 1 : 0);
    h[2] = r2 = (r2 + carry) & mask + ((carry = (r2 + carry) >> 51) > 0 ? 1 : 0);
    h[3] = r3 = (r3 + carry) & mask + ((carry = (r3 + carry) >> 51) > 0 ? 1 : 0);
    h[4] = r4 = (r4 + carry) & mask + ((carry = (r4 + carry) >> 51) > 0 ? 1 : 0);
}


Here's is another transformation using early computation of the masked versions:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t r0 = (uint128_t) f[0] * g[0];
    uint128_t r1 = (uint128_t) f[0] * g[1];
    uint128_t r2 = (uint128_t) f[0] * g[2];
    uint128_t r3 = (uint128_t) f[0] * g[3];
    uint128_t r4 = (uint128_t) f[0] * g[4];

    f1_19 = 19ULL * ((uint64_t)f[1]);
    r0 += (f1_19 * ((uint64_t)g[4]));
    r1 += ((uint128_t) f[1] * g[0]);
    r2 += ((uint128_t) f[1] * g[1]);
    r3 += ((uint128_t) f[1] * g[2]);
    r4 += ((uint128_t) f[1] * g[3]);

    f2_19 = 19ULL * ((uint64_t)f[2]);
    r0 += (f2_19 * ((uint64_t)g[3]));
    r1 += (f2_19 * ((uint64_t)g[4]));
    r2 += ((uint128_t) f[2] * g[0]);
    r3 += ((uint128_t) f[2] * g[1]);
    r4 += ((uint128_t) f[2] * g[2]);

    f3_19 = 19ULL * ((uint64_t)f[3]);
    r0 += (f3_19 * ((uint64_t)g[2]));
    r1 += (f3_19 * ((uint64_t)g[3]));
    r2 += (f3_19 * ((uint64_t)g[4]));
    r3 += ((uint128_t) f[3] * g[0]);
    r4 += ((uint128_t) f[3] * g[1]);

    f4_19 = 19ULL * ((uint64_t)f[4]);
    r0 += (f4_19 * ((uint64_t)g[1]));
    r1 += (f4_19 * ((uint64_t)g[2]));
    r2 += (f4_19 * ((uint64_t)g[3]));
    r3 += (f4_19 * ((uint64_t)g[4]));
    r4 += ((uint128_t) f[4] * g[0]);

    /* Reduce coefficient */
    r00 = ((uint64_t) r0) & mask;
    carry  = (uint64_t) (r0 >> 51);
    r1 += carry;
    r01 = ((uint64_t) r1) & mask;
    carry = (uint64_t) (r1 >> 51);
    ....
