
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_extended[5], f_times_19[4], g_extended[5];
    uint64_t r_final[5], carry;

    for (uint8_t i = 0; i < 5; i++)
    {
        f_extended[i] = (uint128_t) f[i];
        g_extended[i] = (uint128_t) g[i];
    }

    for (uint8_t i = 1; i < 5; i++)
        f_times_19[i-1] = 19ULL * f_extended[i];

    r[0] = f_extended[0] * g_extended[0] + f_times_19[3] * g_extended[4] + f_times_19[1] * g_extended[3] + f_times_19[2] * g_extended[2] + f_times_19[0] * g_extended[1];
    r[1] = f_extended[0] * g_extended[1] + f_extended[1] * g_extended[0] + f_times_19[1] * g_extended[4] + f_times_19[2] * g_extended[3] + f_times_19[0] * g_extended[2];
    r[2] = f_extended[0] * g_extended[2] + f_extended[1] * g_extended[1] + f_extended[2] * g_extended[0] + f_times_19[2] * g_extended[4] + f_times_19[0] * g_extended[3];
    r[3] = f_extended[0] * g_extended[3] + f_extended[1] * g_extended[2] + f_extended[2] * g_extended[1] + f_extended[3] * g_extended[0] + f_times_19[0] * g_extended[4];
    r[4] = f_extended[0] * g_extended[4] + f_extended[1] * g_extended[3] + f_extended[2] * g_extended[2] + f_extended[3] * g_extended[1] + f_extended[4] * g_extended[0];

    for (uint8_t i = 0; i < 5; i++)
    {
        r_final[i]  = (r[i]) & mask;
        carry       = (uint64_t) (r[i] >> 51);
        r[(i+1)%5] += carry;

        if(i < 4)
        {
            r_final[i]          &= mask;
            r_final[(i+1)%5]    += r_final[i] >> 51;
        }
        else
            r_final[0] += 19ULL * (r_final[i]>>51);
    }

    for (uint8_t i = 0; i < 5; i++)
        h[i] = r_final[i];
}
