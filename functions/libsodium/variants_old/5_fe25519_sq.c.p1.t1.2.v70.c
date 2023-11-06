
void fe25519_sq(fe25519 h, const fe25519 f)
{
    uint128_t f_array[5], doubles[2], products[6], result[5], carry;
    const uint64_t mask = 0x7ffffffffffffULL;

    for (int i = 0; i < 5; i++)
        f_array[i] = (uint128_t) f[i];

    doubles[0] = f_array[0] << 1;
    doubles[1] = f_array[1] << 1;

    products[0] = 38ULL * f_array[1];
    products[1] = 38ULL * f_array[2];
    products[2] = 19ULL * f_array[3] << 1;
    products[3] = 38ULL * f_array[3];
    products[4] = 19ULL * f_array[4];
    products[5] = 38ULL * f_array[4];

    result[0] = f_array[0] * f_array[0] + products[0] * f_array[4] + products[1] * f_array[3];
    result[1] = doubles[0] * f_array[1] + products[1] * f_array[4] + f_array[3] * f_array[3];
    result[2] = doubles[0] * f_array[2]  + f_array[1] * f_array[1] + products[3] * f_array[4];
    result[3] = doubles[0] * f_array[3] + doubles[1] * f_array[2] + products[4] * f_array[4];
    result[4] = doubles[0] * f_array[4] + doubles[1] * f_array[3] + f_array[2] * f_array[2];

    for (int i = 0; i < 4; i++)
    {
        result[i + 1] += (uint64_t) (result[i] >> 51);
        h[i] = ((uint64_t) result[i]) & mask;
    }

    h[4] = ((uint64_t) result[4]) & mask;
    carry = (uint64_t) (result[4] >> 51);

    for (int i = 0; i < 3; i++)
    {
        h[i] += carry * 19ULL;
        carry = h[i] >> 51;
        h[i] &= mask;
    }
    h[2] += carry;
}

