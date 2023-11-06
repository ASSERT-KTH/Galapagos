Variant 1:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;
    const uint64_t nineteen = 19ULL;

    uint128_t f0 = (uint128_t) f[0];
    uint128_t f1 = (uint128_t) f[1];
    uint128_t f2 = (uint128_t) f[2];
    uint128_t f3 = (uint128_t) f[3];
    uint128_t f4 = (uint128_t) f[4];

    uint128_t g0 = (uint128_t) g[0];
    uint128_t g1 = (uint128_t) g[1];
    uint128_t g2 = (uint128_t) g[2];
    uint128_t g3 = (uint128_t) g[3];
    uint128_t g4 = (uint128_t) g[4];

    uint128_t f1_19 = nineteen * f1;
    uint128_t f2_19 = nineteen * f2;
    uint128_t f3_19 = nineteen * f3;
    uint128_t f4_19 = nineteen * f4;

    r0 = construct_r0(f0, g0, f1_19, g4, f2_19, g3, f3_19, g2, f4_19, g1);
    r1 = construct_rn(f0, g1, f1, g0,  f2_19, g4, f3_19, g3, f4_19, g2);
    r2 = construct_rn(f0, g2, f1, g1,  f2, g0,  f3_19, g4, f4_19, g3);
    r3 = construct_rn(f0, g3, f1, g2,  f2, g1,  f3, g0,  f4_19, g4);
    r4 = construct_rn(f0, g4, f1, g3,  f2, g2,  f3, g1,  f4, g0);

    calculate_carry(mask, &r0, &r00, &carry);
    calculate_carry(mask, &r1, &r01, &carry);
    calculate_carry(mask, &r2, &r02, &carry);
    calculate_carry(mask, &r3, &r03, &carry);
    calculate_carry(mask, &r4, &r04, &carry);

    r00 += nineteen * carry;
    carry = r00 >> 51;
    r00 &= mask;

    r01 += carry;
    carry = r01 >> 51;
    r01 &= mask;

    r02 += carry;

    fill_h_values(h, r00, r01, r02, r03, r04);
}


Variant 2:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;
    const uint64_t nineteen = 19ULL;

    uint128_t f_values[5], g_values[5];
    for(int i = 0; i < 5; i++)
    {
        f_values[i] = f[i];
        g_values[i] = g[i];
    }

    uint128_t f_factors[5] = { 1ULL, nineteen*f[1], nineteen*f[2], nineteen*f[3], nineteen*f[4] };
    uint128_t g_factors[5] = { g_values[0], g_values[1], g_values[2], g_values[3], g_values[4] };

    r0 = calc_r(f_values, g_values, f_factors, g_factors, 0);
    r1 = calc_r(f_values, g_values, f_factors, g_factors, 1);
    r2 = calc_r(f_values, g_values, f_factors, g_factors, 2);
    r3 = calc_r(f_values, g_values, f_factors, g_factors, 3);
    r4 = calc_r(f_values, g_values, f_factors, g_factors, 4);

    calculate_carry_and_value(mask, &r0, &r00, &carry);
    calculate_carry_and_value(mask, &r1, &r01, &carry);
    calculate_carry_and_value(mask, &r2, &r02, &carry);
    calculate_carry_and_value(mask, &r3, &r03, &carry);
    calculate_carry_and_value(mask, &r4, &r04, &carry);

    r00 += nineteen * carry;
    carry = r00 >> 51;
    r00 &= mask;
    r01 += carry;
    carry  = r01 >> 51;
    r01 &= mask;
    r02 += carry;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}

Example variant here. Depending on how you want to balance readability versus avoidance of redundancy, you could refactor more or less. Likewise, review your coding style guide as some guides favor multiple simple instructions (improves human-likeness of code & is easier to debug) over fewer complex instructions.