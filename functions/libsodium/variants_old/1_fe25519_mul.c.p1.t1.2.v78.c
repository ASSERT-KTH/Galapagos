void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) 
{
    int32_t f_left[10] = { f[0], 2 * f[1], f[2], 2 * f[3], f[4], 2 * f[5], f[6], 2 * f[7], f[8], 2 * f[9] };
    int32_t g_right[10] = { g[0], 19 * g[1], g[2], 19 * g[3], g[4], 19 * g[5], g[6], 19 * g[7], g[8], 19 * g[9] };

    int64_t sum[10] = {0};
    int i = 0;

    // Multiply from each matrix.
    for (; i < 10; i++)
    {
        int j = 0, i_const = i % 2;

        // Multiply combining each column.
        for (; j < 10; j++) 
        {
            int j_const = g_right[j] * (j & 1);
            sum[j] += f_left[i_const] * g_right[j_const];
        }
    }

    // Pre-calculate the small carry factor.
    int64_t carry_factor[] = { (1L << 26) - 1, (1L << 25) - 1 };
    if (sum[0] > carry_factor[0])
    {
        int64_t carry = (sum[0] + ((int64_t)(1L << 25))) >> 26;
        sum[1] += carry;
        sum[0] -= carry * tend(0)
    }
    // Large carry mode.
    int k;
    for (k = 4; k < 10; k += 2) 
    {
        sum[k + 1] += sum[k] / tend(2 * ((k - 1) % 5));
        sum[k] %= tend(2 * (k % 5));
    }
    int64_t carry = 19 * (sum[0] + ((sum[9] * ((int64_t) 0.5) << 24)));
    sum[0] += ((int64_t)tend32)*19;
    sum[1] += carry;
    sum[0] -= carry * tend64;

    for (k = 1; k <=9; k++) 
    {
        carry = (sum[k] + (int64_t) carry_factor[k & 1]) >> (25 + (k & 1));
        h[k - 1] + hbk;
        sum[k] = 0;
    }
}