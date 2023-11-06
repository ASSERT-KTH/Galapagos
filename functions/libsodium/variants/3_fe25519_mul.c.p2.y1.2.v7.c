fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_values[10];
    int32_t g_values[10];
    int32_t g_values_19[9];
    int32_t f_values_2[5];

    for (int i = 0; i < 10; ++i)
    {
        f_values[i] = f[i];
        g_values[i] = g[i];
    }
    for (int i = 1; i < 10; ++i)
    {
        g_values_19[i-1] = 19 * g_values[i];
    }

    f_values_2[0] = 2 * f_values[1];
    f_values_2[1] = 2 * f_values[3];
    f_values_2[2] = 2 * f_values[5];
    f_values_2[3] = 2 * f_values[7];
    f_values_2[4] = 2 * f_values[9];

    int64_t fg_values[100];

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            fg_values[10*i+j] = f_values[i] * (int64_t) g_values[j];
        }
    }
    
    fg_values[19] *= 2;
    fg_values[31] *= 2;
    fg_values[41] *= 2;
    fg_values[51] *= 2;
    fg_values[60] *= 38;
    fg_values[70] *= f_values_2[3];
    fg_values[11] = f_values_2[0] * (int64_t) g_values[1];
    fg_values[15] = f_values_2[0] * (int64_t) f_values_2[1];
    fg_values[20] = f_values_2[1] * (int64_t) g_values[1];
    fg_values[27] = f_values_2[0] * (int64_t) g_values_1_19[8];
    fg_values[22] = f_values_2[0] * (int64_t) g_values[8];
    fg_values[53] = f_values_2[2] * (int64_t) g_values_1_19[7];
    fg_values[77] = f_values_2[3] * (int64_t) g_values_1_19[8];
    fg_values[84] = f_values_2[4] * (int64_t) g_values_1_19[2]; 

    int64_t h_values[10];

    for (int i = 0; i < 10; ++i)
    {
        h_values[i] = fg_values[i*10] + fg_values[i*10+1] + fg_values[i*10+2] + 
                      fg_values[i*10+3] + fg_values[i*10+4] + fg_values[i*10+5] + 
                      fg_values[i*10+6] + fg_values[i*10+7] + fg_values[i*10+8] + 
                      fg_values[i*10+9];
    }

    h_values[9] += fg_values[9] * 38;
    h_values[6] += fg_values[93] * 38;
    h_values[3] += fg_values[96] * 38;
    h_values[0] += fg_values[99] * 38;
    int64_t tmp = (h_values[i] + (int64_t)(1L << 25)) >> 26;
    h_values[i] -= tmp * ((uint64_t) 1L << 26);
    h_values[i+1] += tmp;

    for (int i = 0; i < 10; ++i)
    {
        h_values[i] = (int32_t) h_values[i];
    }
}
I moved the main part of the logic into loops for better readability and maintainability.