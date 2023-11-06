void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t temp[10] = {0};
    int64_t carry;
    int i,j;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j <= i; j++)
        {
            temp[i] += (int64_t)f[j] * ((i == j) ? g[i] : 2 * g[i - j]);
        }
        for (j = i + 1; j < 10; j++)
        {
            temp[i] += 38 * (int64_t)f[j] * ((i+j == j+j) ? g[i + 10 - j] : 2 * g[i + 10 - j]);
        }
    }
    // reduce carried bits
    for (i = 0; i < 9; i++)
    {
        carry = (temp[i] + (1 << 25)) >> 26;
        temp[i + 1] += carry;
        temp[i] -= ((int64_t) carry * (1 << 26));
    }

    // reduce everything once more
    carry = (temp[9] + (1 << 24)) >> 25;
    temp[0] += carry * 19;
    temp[9] -= ((int64_t) carry * (1 << 25));

    for (i = 0; i < 10; i++)
    {
        carry = (temp[i] + (1 << 25)) >> 26;
        h[(i == 9) ? 0 : (i + 1)] += carry;
        h[i] = temp[i] - ((int64_t) carry * (i == 9 ? 38 : (1 << 26)));
    }
}