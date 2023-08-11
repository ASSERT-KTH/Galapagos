Here is a variant of the function that changes its behaviour in the implementation but achieves similar functionality:


void fe25519_mul_v(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t product[19] = {0}; // Stores product of each element

    // Calculate product of each possible (f_i, g_j) pair
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            product[i+j] += (int64_t)f[i] * g[j];
        }
    }

    // Adjust weights by reducing from higher weighted positions
    typedef struct carry_and_index_t { int64_t carry; int index; } carry_and_index;
    const carry_and_index reductions[4] = { {19, 2}, {19, 4}, {19, 6}, {19, 8} };

    for (int i = 0; i < 4; ++i)
    {
        int64_t carry = product[reductions[i].index] >> 26;
        product[(reductions[i].index - 2) % 10] += carry;
        product[reductions[i].index] -= carry << 26;
    }

    // Apply final carries
    int64_t carry = product[9] >> 24;
    product[0] += carry * 19;
    product[9] -= carry << 24;

    carry = product[0] >> 26;
    product[1] += carry;
    product[0] -= carry << 26;

    // Assign to the result array
    for (int i = 0; i < 10; ++i)
    {
        h[i] = (int32_t)product[i];
    }
}

The previous reference implementation uses an explicit chaos carry propagation method based on  Elliptic Curve Arithmetic operations, also known as DECE coordinates, and handling the extra bit that flows from multiplication since the geometric-level operation results a larger value. 
The change to the algorithm in the variant algorithm is floating point precision carry. This variant goes straight forward into calculating the values of all the possible f*g combinations considering their weight, and then reduces using the Heirarchical Carry Limit algorithm upon the weights until the moduli (mod p). Every group is weighting under the elliptic curve parameters(19^i for carry), so we go step by step reducing the values by 2^26 to normalize previous weights. 
Finally settle down on a case by case basis for corner weights (-1, in floating point 19).