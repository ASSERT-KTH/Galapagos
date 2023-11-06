Here are three different code-transformed versions of the original function:


Transformation 1: Reordered code sequence


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  r00, r01, r02, r03, r04, carry;

    f0 = f[0]; g0 = g[0];
    f1 = f[1]; g1 = g[1]; f1 = 19ULL * f1;
    f2 = f[2]; g2 = g[2]; f2 = 19ULL * f2;
    f3 = f[3]; g3 = g[3]; f3 = 19ULL * f3;
    f4 = f[4]; g4 = g[4]; f4 = 19ULL * f4;

    r0 = (f0 * g0 + f1 * g4 + f2 * g3 + f3 * g2 + f4 * g1);
    r1 = (f0 * g1 + g0 + f2 * g4 + f1 + f4 * g3);
    r2 = (f0 * g2 + g1 + f2 + f3 * g4 + f4 * g3);
    r3 = (f0 * g3 + g2 + g1 + f3 + f4 * g4);
    r4 = (f0 * g4 + g3 + g2 + g1 + g0);

    carry  = (uint64_t)(r1 >> 51);  r00  = r0 & mask;  r1 += carry;
    carry  = (uint64_t)(r2 >> 51);  r01  = r1 & mask;  r2 += carry;
    carry  = (uint64_t)(r3 >> 51);  r02  = r2 & mask;  r3 += carry;
    carry  = (uint64_t)(r4 >> 51);  r03  = r3 & mask;  r4 += carry;
    
    carry  = (uint64_t)(r0 >> 51);  r4 += carry;        r00  += 19ULL * carry; 
    carry  = r00 >> 51;             r04 = r4 & mask;    r00 &= mask; 

    carry = r01 >> 51;  r01 &= mask;
    r02 += carry;
    
    h[0] = r00; h[1] = r01; h[2] = r02; h[3] = r03; h[4] = r04;
}


Transformation 2: Using compact assignments


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t g0,g1,g2,g3,g4;
    uint128_t f0 = f[0], f1 = (uint128_t)19 * f[1], f2 =(uint128_t)19 * f[2], f3 =(uint128_t)19 * f[3], f4 =(uint128_t)19 * f[4];
    uint64_t r00, r01, r02, r03, r04, carry;

    g0 = g[0]; g1 = g[1]; g2 = g[2]; g3 = g[3]; g4 = g[4];

    r0 = (f0 * g0 + f1 * g4 + f2 * g3 + f3 * g2 + f4 * g1);
    r1 = (f0 * g1 +    f1 * g0 + f2 * g4 + f3 * g3 + f4 * g2);
    r2 = (f0 * g2 +    f1 * g1 +    f2 * g0 + f3 * g4 + f4 * g3);
    r3 = (f0 * g3 +    f1 * g2 +    f2 * g1 +    f3 * g0 + f4 * g4);
    r4 = (f0 * g4 +    f1 * g3 +    f2 * g2 +    f3 * g1 +    
        f4 * g0);
    carry = r0 >> 51; r00 = r0 & mask; r1 += carry;
    carry = r1 >> 51; r01 = r1 & mask; r2 += carry;
    carry = r2 >> 51; r02 = r2 & mask; r3 += carry;
    carry = r3 >> 51; r03 = r3 & mask; r4 += carry;
    carry = r4 >> 51; r04 = r4 & mask; r01+= carry;
    carry = r00 >> 51; r00 &= mask; r00 += 19 * carry;


    h[0] = r00 + carry; h[1] = r01 + carry; h[2] = r02 + carry; h[3] = r03; h[4] = r04;
}

Transformation 3: Simplified variable assignment sequence and compact calculations.


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t f0 = f[0], f1 = 19 * f[1], f2 = 19 * f[2], f3 = 19 * f[3], f4 = 19 * f[4];
    uint128_t g0 = g[0], g1 = g[1], g2 = g[2], g3 = g[3], g4 = g[4];
    uint128_t r0, r1, r2, r3, r4;
    uint64_t carry;

    r0 = (f0*g0 + f1*g4 + f2*g3 + f3*g2 + f4*g1) & 0x7ffffffffffffULL;
    r1 = (r0 >> 51ULL) + f0*g1 +       g0 + f1*g3 + f2*g2 + f3*g1 + f4*g0;
    r2 = (r1 >> 51ULL) + f0*g2 + f1*g1 + g0 + f2*g1 + f3*g0 + f4*g3;
    r3 = (r2 >> 51ULL) + f0*g3 + f1*g2 + g1 + f2*g0 + f3*g1 + f4*g2;
    r4 = (r3 >> 51ULL) + f0*g4 + f1*g3 + g2 + f2*g1 + f3*g0 + g1 + f4;

    carry           = r4 >> 51ULL;
    h[0]            = r0 + 19ULL * carry;
    h[1]           = (r1 + (h[0] >> 51ULL)) & 0x7ffffffffffffULL;
    h[0]           &= 0x7ffffffffffffULL;
    h[2]            = (r2 + (h[1] >> 51ULL)) & 0x7ffffffffffffULL;
    h[1]           &= 0x7ffffffffffffULL;
    h[3]            = (r3 + (h[2] >> 51ULL)) & 0x7ffffffffffffULL;
    h[4] = r4    &= 0x7ffffffffffffULL;
}
