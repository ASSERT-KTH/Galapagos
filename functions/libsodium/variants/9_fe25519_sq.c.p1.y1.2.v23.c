Below are some variants of the original function using basic code refactorings like variable reuse, manual loop unrolling, ordering of arithmetic operations, etc. Maintaining the readability of the code is also kept in mind, thus the variable names and the overall organization of the code are similar to the original.

Variant 1:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t currentDouble = 2 * f[0];
    int64_t temp1, temp2, carryTemp;
    for(int i = 0; i < 9; ++i) 
    {
        temp1 = f[i] * (int64_t) f[i];
        temp2 = currentDouble * (int64_t) f[i+1];

        switch (i) 
        {
            case 3:
            case 5:
                temp2 *= 2;
                break;

            default:
                temp2 %= 19;
                break;
        }
        h[i] = temp1 + temp2;

        carryTemp = (h[i] + (int64_t)(1L << (i % 2 == 0 ? 25 : 24))) >> (i % 2 == 0 ? 26 : 25);
        h[i+1] += carryTemp;
        h[i] -= carryTemp * ((uint64_t) (i % 2 == 0 ? (1L << 26) : (1L << 25)));

        currentDouble = 2 * f[i+1];
    }
    h[9] = f[9] * (int64_t) f[9];
    carryTemp = (h[9] + (int64_t)(1L << 24)) >> 25;
    h[0] += carryTemp * 19;
    h[9] -= carryTemp * ((uint64_t) 1L << 25);
    carryTemp = (h[0] + (int64_t)(1L << 25)) >> 26;
    h[1] += carryTemp;
    h[0] -= carryTemp * ((uint64_t) 1L << 26);
}


Variant 2:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t carry[10] = {0}, tDouble;
    for(int i = 0; i < 10; ++i)
    {
        tDouble = 2 * f[i];
        for(int j = 0; j < 10; ++j)
        {
            if (j < i + 1)
                carry[j + i] = tDouble * (int64_t) f[j] + h[i + j];
            else
                break;
        }
        h[i] = carry[i];
    }

    for(int i = 0; i < 9; i++)
    {
        carry[i + 1] += h[i] >> (i % 2 == 0 ? 26 : 25);
        h[i] %= (i % 2 == 0 ? (1LL << 26) - 1 : (1LL << 25) - 1);
    }

    h[0] += (h[9] >> ((int64_t)1L << 24)) * 38;
    h[9] %= (1LL << 24) - 1;
    h[1] += (h[0] >> 26);
    h[0] %= ((int64_t)1L << 26);
}
