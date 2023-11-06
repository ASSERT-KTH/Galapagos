Here's an equivalent program containing minor transformations that do not change the objective of the original code. Variations include re-ordering of instructions, different initialization of constants and additional brackets for enforcing operation's precedence.


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4, f1_19, f2_19, f3_19, f4_19;
    uint128_t g1,g2,g3,g4,g0;
    uint64_t  r01, r02, r03, r04, r00;
    uint64_t  carry;
    uint64_t mask = 0x7ffffffffffffULL;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = f[2]; f3 = (uint128_t) f[3]; f4 = (uint128_t) f[4];
    g4 = (uint128_t) g[4]; g3 = (uint128_t) g[3]; g2 = (uint128_t) g[2]; g1 = (uint128_t) g[1]; g0 = (uint128_t) g[0];
    f1_19 = 19ULL * f1;
    f2_19 = 19ULL * f2;
    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;
    r4 = f0 * g1 + f1 * g3 + f2 * g2 + f3 * g3 + f4 * g0;
    r3 = f0 * g2 + f1 * g1 + f2 * g0 + f4_19 * g4 + f3_19 * g3;
    r2 = f0 * g1 + f1 * g0 + f4_19 * g3 + f2_19 * g4 + f3_19 * g2;
    r1 = f0 * g0 + f1_19 * g4 + f3_19 * g2 + f4_19 * g1 + f2_19 * g3;
    r0 = f0 * g0 + f4_19 * g1 + f1_19 * g4 + f3_19 * g2 + f2_19 * g3;

    r00 = (((uint64_t) r0) & mask); carry = (uint64_t) (r0 >> 51); r1 += carry;
    r01 = (((uint64_t) r1) & mask); carry = (uint64_t) (r1 >> 51); r2 += carry;
    r02 = (((uint64_t) r2) & mask); carry = (uint64_t) (r2 >> 51); r3 += carry;
    r03 = (((uint64_t) r3) & mask); carry = (uint64_t) (r3 >> 51); r4 += carry;
    r04 = (uint64_t) (r4 & mask); carry = (uint64_t) (r4 >> 51);
    r00 += (19ULL * carry);
    h[4] = r04;
    r00 = r00 & mask; carry = r00 >> 51; r01 += carry;
    r01 = r01 & mask; carry = r01 >> 51; r02 += carry;

    h[3] = r03;
    h[0] = r00;
    h[2] = r02;
    h[1] = r01;
}
