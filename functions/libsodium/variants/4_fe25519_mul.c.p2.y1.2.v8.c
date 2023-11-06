void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t f_vals[5], g_vals[5], f_19_vals[5], r_vals[5];
    const uint64_t mask = 0x7ffffffffffffULL;

    uint64_t  r_vals_final[5];
    uint64_t  carry;

    for (uint8_t i = 0; i < 5; ++i)
    {
        f_vals[i] = (uint128_t) f[i];
        g_vals[i] = (uint128_t) g[i];
        f_19_vals[i] = i ? 19ULL * f[i] : 0;
    }

    r_vals[0] = f_vals[0] * g_vals[0] + f_19_vals[1] * g_vals[4] + f_19_vals[2] * g_vals[3] + f_19_vals[3] * g_vals[2] + f_19_vals[4] * g_vals[1];
    r_vals[1] = f_vals[0] * g_vals[1] + f_vals[1] * g_vals[0] + f_19_vals[2] * g_vals[4] + f_19_vals[3] * g_vals[3] + f_19_vals[4] * g_vals[2];
    r_vals[2] = f_vals[0] * g_vals[2] + f_vals[1] * g_vals[1] + f_vals[2] * g_vals[0] + f_19_vals[3] * g_vals[4] + f_19_vals[4] * g_vals[3];
    r_vals[3] = f_vals[0] * g_vals[3] + f_vals[1] * g_vals[2] + f_vals[2] * g_vals[1] + f_vals[3] * g_vals[0] + f_19_vals[4] * g_vals[4];
    r_vals[4] = f_vals[0] * g_vals[4] + f_vals[1] * g_vals[3] + f_vals[2] * g_vals[2] + f_vals[3] * g_vals[1] + f_vals[4] * g_vals[0];
	
    for( uint8_t i = 0; i < 5; ++i )
    {
        r_vals_final[i] = ((uint64_t) r_vals[i]) & mask;
        carry  = (uint64_t) (r_vals[i] >> 51);
        r_vals[i+1] += carry;
        r_vals_final[i] += 19 * (i > 3 ? carry : 0);
        carry  = r_vals_final[i] >> 51;
        r_vals_final[i] &= mask;
        r_vals_final[i+1] += carry;
    }

    for (uint8_t i = 0; i < 5; ++i)
        h[i] = r_vals_final[i];
}