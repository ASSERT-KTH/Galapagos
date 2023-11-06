
fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    uint128_t f0 = f[0];
    uint128_t f1 = f[1];
    uint128_t f2 = f[2];
    uint128_t f3 = f[3];
    uint128_t f4 = f[4];

    // utilization of derived variables in single line
    uint128_t r0 = f0 * f0 + (38 * f1) * f4 + (38 * f2) * f3;
    uint128_t r1 = (f0 +f0) * f1 + (38 * f2) * f4 + (19 * f3) * f3;
    uint128_t r2 = (f0 << 1) * f2 + f1 * f1 + (38 * f3) * f4;
    uint128_t r3 = (2 * f0) * f3 + 2 * f1 * f2  + 19 * f4 * f4;
    uint128_t r4 = f0 * (f4 << 1) + (2 * f1) * f3  + f2 * f2;

    // inline use derived variable `carry`, range restriction ('& mask') and integer reduction (carry - 19 * ...)
    h[0] = ((r00 = (((uint64_t) r0) & mask) + 19 * (carry = (uint64_t) ((r0 + (r1 += (carry = (uint64_t)r0 >> 51))) >> 51))) >> 51) * 19);
    r00 &= mask;
    h[1] = ((r01 = (((uint64_t) r1) & mask) +             (carry = (uint64_t) (r01 >> 51))) >> 51);
    r01 &= mask;
    h[2] = ((r02 = (((uint64_t) (r2 += carry)) & mask))                          >> 51) + r02;
    h[3] = ((uint64_t) ((r3 += carry = ((uint64_t) r2 >> 51)) & mask));
    h[4] = ((uint64_t) ((r4 += carry =((uint64_t) r3 >> 51)) & mask));
}

The solution pushes several concepts of derived variables into a one liner and subsequently simplifies calculations. Do however be aware, every change decreases readability and maintainability.
This solution is mostly correct being given all positive integrals and knowing f1, f2, f3 never being more than 2^107 to not overflow during multiplication by 38 or 19, and generally all parameters of f an order of magnitude smaller to not overflow r0-4. The essence and potential fail scenario remain the same.