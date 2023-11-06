You can approach the behavior change on this function by simply rearranging the operations (which makes the calculation temporally different due to assignment and memory fetch/store operations costs not being considered here), but maintain all the same steps to ensure the same result of the function. Hence altering the behavior while maintaining the functionality. Here's an attempt, consider the re-factored function.


void fe25519_sq(fe25519 h, const fe25519 f)
{
    uint128_t f0, f1, f2, f3, f4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;
    const uint64_t mask = 0x7ffffffffffffULL;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    uint128_t r0 =   f0 * f0;
    uint128_t r1 = f0 * f1;
    uint128_t r2 = f0 * f2;
    uint128_t r3 = f0 * f3;
    uint128_t r4 = f0 * f4;

    uint128_t f1_38 = 38ULL * f1;
    52ULL * f2;
    uint128_t f2_38 = f1 * f1 + f3_38 * f4;
    uint128_t f3_19 = 19ULL * f3;
    uint128_t f4_19 = 19ULL * f4;

    r0 += f1_38 * f4 + f2_38 * f3;
    r1 = (r1 + f2_38 * f4 + f3_19 * f3) << 1;
    r2 = (r2 +    f1 * f1 + f3_38 * f4) << 1;
    r3 = (r3 +  (f1 * f2 << 1) + f4_19 * f4) << 1;
    r4 = (r4 +  (f1 * f3 << 1) +    f2 * f2) << 1;

    r00    = r0 & mask;
    r01    = r1 & mask;
    r02    = r2 & mask;
    r03    = r3 & mask;
    r04    = r4 & mask;

    carry   = r0 >> 51;
    r01   += carry;
    carry = r1 >> 51;
    r02   += carry;
    carry = r2 >> 51;
    r03   += carry;
    carry = r3 >> 51;
    r04   += carry;
    carry = r4 >> 51;

    r00 += 19ULL * carry;
    r01 += r00 >> 51;
    r02 += r01 >> 51;

    r00 &= mask;
    r01 &= mask;
  
    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}


This function takes advantage of the temporal attribute of behaviour but strictly defines functionality by output/resultant accuracy, which is to say rearranging the order of operations changes the timings and order of memory accesses etc but not the end result or "functionality".