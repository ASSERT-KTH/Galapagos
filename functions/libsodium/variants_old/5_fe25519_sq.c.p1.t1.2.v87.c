Here is one way to refactor the function while maintaining the same functionality;


fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t ro = 0, r1 = 0, r2 = 0, r3 = 0, r4 = 0;
    uint128_t f0 = ((uint128_t) f[0]);
    uint128_t f1 = ((uint128_t) f[1]);
    uint128_t f2 = ((uint128_t) f[2]);
    uint128_t f3 = ((uint128_t) f[3]);
    uint128_t f4 = ((uint128_t) f[4]);

    ro = (f0 * f0 + (38ULL * f1 * f4) + (38ULL * f2 * f3));
    r1 = ((f0 << 1) * f1 + (38ULL * f2 * f4) + (19ULL * f3 * f3));
    r2 = ((f0 << 1) * f2 + (f1 * f1) + (38ULL * f3 * f4));
    r3 = ((f0 << 1) * f3 + (f1 << 1) * f2 + (19ULL * f4 * f4));
    r4 = ((f0 << 1) * f4 + (f1 << 1) * f3 + (f2 * f2));

    uint64_t carry = CalculationFn(ro, &ro, mask);
    r1 += carry;
    carry = CalculationFn(r1, &r1, mask);
    r2 += carry;
    carry = CalculationFn(r2, &r2, mask);
    r3 += carry;
    carry = CalculationFn(r3, &r3, mask);
    r4 += carry;
    carry = CalculationFn(r4, &r4, mask);
    ro += 19ULL * carry;
    carry = CalculationFn(ro, &ro, mask);
    r1 += carry;
    carry = CalculationFn(r1, &r1, mask);
    r2 += carry;

    h[0] = ro;
    h[1] = r1;
    h[2] = r2;
    h[3] = r3;
    h[4] = r4;
}

uint64_t CalculationFn(uint128_t number, uint128_t *captureNumber, uint64_t mask)
{
    *captureNumber = ((uint64_t)number) & mask;
    return (uint64_t)(number >> 51);
}

It looks like the exact same calculations are performed as in the original function without adding any additional complexity. Also, with this refactoring approach, a significant duplication was eliminated which helps to keep the code dry (Don't repeat yourself).