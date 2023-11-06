// Variant 1: Loop Optimization
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_arr[10];
    int32_t g_arr[10];
    int32_t g_19_arr[10];
    int64_t h_arr[10];
    int64_t carry_arr[10] = { 0 };

    for (int i = 0; i < 10; i++)
    {
        f_arr[i] = f[i];
        g_arr[i] = g[i];
        if (i != 0)
        {
            g_19_arr[i] = 19 * g[i];
        }
    }

    for (int j = 0; j < 10; j++)
    {
        h_arr[j] = f_arr[0] * (int64_t)g_arr[j];
        if (j != 0)
        {
            h_arr[j] += f_arr[j] * (int64_t)g_19_arr[j] * j;
        }
        carry_arr[j] = (h_arr[j] + (int64_t)(1L << (j + 24))) >> (j + 25);
        i += carry_arr[j];
        h_arr[j] -= carry_arr[j] * ((uint64_t)1L << (j + 25));

    }

    memcpy(h, h_arr, 10 * sizeof(int32_t));
}

// Variant 2: Memory Handling Improvement
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    fe25519 f_cpy, g_cpy;
    memcpy(f_cpy, f, sizeof(fe25519));
    memcpy(g_cpy, g, sizeof(fe25519));

    int32_t g1_19 = 19 * g_cpy[1];
    int32_t g3_19 = 19 * g_cpy[3];
    int32_t g5_19 = 19 * g_cpy[5];
    int32_t g7_19 = 19 * g_cpy[7];
    int32_t g9_19 = 19 * g_cpy[9];
    int32_t f1_2  = 2 * f_cpy[1];
    int32_t f3_2  = 2 * f_cpy[3];
    int32_t f5_2  = 2 * f_cpy[5];
    int32_t f7_2  = 2 * f_cpy[7];
    int32_t f9_2  = 2 * f_cpy[9];

    int64_t h[10];
    // create algorithm
    memcpy(fe25519, h, sizeof(h));
}