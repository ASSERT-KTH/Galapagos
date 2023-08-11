int fe25519_sq(fe25519 h, const fe25519 f)
{
    uint128_t f0, f1, f2, f3, f4;
    uint64_t carry;
    const uint64_t mask = ((uint64_t)1 << 51) - 1;

    f0 = (uint128_t)f[0];
    f1 = (uint128_t)f[1];
    f2 = (uint128_t)f[2];
    f3 = (uint128_t)f[3];
    f4 = (uint128_t)f[4];

    uint128_t a =    f0*f0 + 38*f4*f1 + 19*f3*f2;
    uint128_t b = 2*(f0*f1 + 19*f4*f2 +  f3*f3);
    uint128_t c = 2*(f0*f2) + f1*f1 + 38*f4*f3;
    uint128_t d = 2*(f0*f3 + f1*f2     ) + 19*f4*f4;
    uint128_t e = 2*(f0*f4 + f1*f3) +    f2*f2;

    emplace_narrowing (&h[0], a, mask, &carry);
    emplace_narrowing (&h[1], carry + b, mask, &carry);
    emplace_narrowing (&h[2], carry + c, mask, &carry);
    emplace_narrowing (&h[3], carry + d, mask, &carry);
    emplace_narrowing (&h[4], carry + e, mask, &carry);
    h[0] += 19ULL*carry;

    if ((a = h[0] >> 51) != 0) { h[0] &= mask; h[1] += a; }
    if ((a = h[1] >> 51) != 0) { h[1] &= mask; h[2] += a; }
    if ((a = h[2] >> 51) != 0) { h[2] &= mask; h[3] += a; }
    if ((a = h[3] >> 51) != 0) { h[3] &= mask; h[4] += a; }
    if ((a = h[4] >> 51) != 0) { h[4] &= mask; h[0] += 19ULL*a; }
    carry = h[0] >> 51; h[0] &= mask;
    h[1] += carry;

    return 0;
}
Note: Please replace definition/declaration of `emplace_narrowing` with its original/original-like definition for the function to properly work. In short, its purpose is to put a narrowed down+masked value from a `uint128_t` value into a `uint64_t` space purely under our control avoiding incidental overflows.