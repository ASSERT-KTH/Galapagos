The variant of the program may opt to assign constant values first, neatly group 128-bit computations, then move to carry operations afterwards. This involves doing pretty much the same steps but just varying the groupings and ordering:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    const uint64_t f38 = 38ULL, f19 = 19ULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    f0 = ((uint128_t) f[0]) << 1;
    f1 = ((uint128_t) f[1]) << 1;
    f2 = ((uint128_t) f[2]);
    f3 = ((uint128_t) f[3]);
    f4 = ((uint128_t) f[4]);

    r0 = (f0 * f0) / 2 + f38 * f1 * f4 / 2 + f38 * f2 * f3 / 2;
    r1 = f0 * f[1] + f38 * f2 * f4 / 2 + f19 * f3 * f3;
    r2 = f0 * f[2] / 2 + f1 * f[1] + f38 * f3 * f4 / 2;
    r3 = f0 * f[3] / 2 + f1 * f[2] / 2 + f19 * f4 * f4;
    r4 = f0 * f[4] / 2 + f1 * f[3] / 2 + f2 * f2;

    uint64_t temp_carry = r0 >> 51; 
    r00 = (r0 + temp_carry - (temp_carry << 51)) & mask;
    r1 += temp_carry >> 1;

    temp_carry = r1 >> 51;
    r01 = (r1 + temp_carry - (temp_carry << 51)) & mask;
    r2 += temp_carry >> 1;

    temp_carry = r2 >> 51;
    r02 = (r2 + temp_carry - (temp_carry << 51)) & mask;
    r3 += temp_carry >> 1;

    temp_carry = r3 >> 51;
    r03 = (r3 + temp_carry - (temp_carry << 51)) & mask;
    r4 += temp_carry >> 1;

    temp_carry = r4 >> 51;
    r04 = (r4 + temp_carry - (temp_carry << 51)) & mask;
    r00 += f19 * (temp_carry >> 1);

    carry = r00 >> 51; 
    r00 = (r00 + carry - (carry << 51)) & mask;
    r01 += (carry >> 1);
    carry = r01 >> 51;
    r01 = (r01 + carry - (carry << 51)) & mask;
    r02 += (carry >> 1);

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}
