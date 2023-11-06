Variant 1: Using macro for duplicate code segments

#define CARRY_CALC_HELPER(i, j, k, l)   \
digit##i = (h##i + (int64_t)(1L << j)) >> k; \
h##l += digit##i; \
h##i -= digit##i * ((uint64_t) 1L << k);

void fe25519_sq(fe25519 h, const fe25519 f)
{
    .

    .

    .

    int64_t digit0, digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8, digit9;

    CARRY_CALC_HELPER(0, 25, 26, 1)
    CARRY_CALC_HELPER(4, 25, 26, 5)
    CARRY_CALC_HELPER(1, 24, 25, 2)
    CARRY_CALC_HELPER(5, 24, 25, 6)
    CARRY_CALC_HELPER(2, 25, 26, 3)
    CARRY_CALC_HELPER(6, 25, 26, 7)
    CARRY_CALC_HELPER(3, 24, 25, 4)
    CARRY_CALC_HELPER(7, 24, 25, 8)
    CARRY_CALC_HELPER(4, 25, 26, 5)
    CARRY_CALC_HELPER(8, 25, 26, 9)
    CARRY_CALC_HELPER(9, 24, 25, 0)
    CARRY_CALC_HELPER(0, 9, 26, 1)

    .

    .

    .
}


Variant 2: Reversing loop order

void fe25519_sq(fe25519 h, const fe25519 f)
{
    for (int i = 9; i >= 0; --i)
    {
        int32_t t = f[i];
    }
    .

    .

    .

    for (int i = 9; i >= 0; --i)
    {
        h[i] = (int32_t)
    }

    .

    .

    .

    for (int j = 4; j >= 0; --j)
    {
        int32_t t1 = 2*f[j+5];
        int32_t t2 = 38*f[j+5];
        f[j * 2] = t1 * f0;
    }

    .

    .

    .

}


Variant 3: Factor common operations

void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t temp[10];

    for (int i = 0; i < 10; i++)
    {
        temp[i] = f[i] * 2;
    }

    .

    .

    .

    for (int64_t i = 9; i >= 0; i-- ) {
        f0f_##i = f0 * f[i];
    }

    .

    .

    .

    for (int64_t i = 9; i >= 0; i-- ) {
        h[i] = carry + 19 * (int64_t) h9;
    }

    .

    .

    .
}
