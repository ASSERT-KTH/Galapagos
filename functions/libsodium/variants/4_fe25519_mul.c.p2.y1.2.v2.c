
fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t h0, h1, h2, h3, h4;
    uint128_t f1_times19, f2_times19, f3_times19, f4_times19;
    uint128_t carry;
    uint128_t f_64[5], g_64[5];
    const uint64_t mask = 0x7ffffffffffffULL;

    for(int i=0; i<5; i++)
    {
        f_64[i] = (uint128_t)f[i];
        g_64[i] = (uint128_t)g[i];
    }

    f1_times19 = 19ULL * f_64[1];
    f2_times19 = 19ULL * f_64[2];
    f3_times19 = 19ULL * f_64[3];
    f4_times19 = 19ULL * f_64[4];

    h0 = f_64[0]*g_64[0] +     f4_times19 * g_64[1] + f3_times19 * g_64[2] + f2_times19 * g_64[3] + f1_times19 * g_64[4];
    h1 = f_64[0]*g_64[1] + f_64[1]*g_64[0] +     f4_times19 * g_64[2] + f3_times19 * g_64[3] + f2_times19 * g_64[4];
    h2 = f_64[0]*g_64[2] + f_64[1]*g_64[1] + f_64[2]*g_64[0] +     f4_times19 * g_64[3] + f3_times19 * g_64[4];
    h3 = f_64[0]*g_64[3] + f_64[1]*g_64[2] + f_64[2]*g_64[1] + f_64[3]*g_64[0] +     f4_times19 * g_64[4];
    h4 = f_64[0]*g_64[4] + f_64[1]*g_64[3] + f_64[2]*g_64[2] + f_64[3]*g_64[1] + f_64[4]*g_64[0];

    carry = h0 >> 51; h0 &= mask; h1 += carry;
    carry = h1 >> 51; h1 &= mask; h2 += carry;
    carry = h2 >> 51; h2 &= mask; h3 += carry;
    carry = h3 >> 51; h3 &= mask; h4 += carry;
    carry = h4 >> 51; h4 &= mask;
    h4 += carry; 
    h0 += 19*carry; 

    h[0] = (uint64_t) h0;
    h[1] = (uint64_t) h1;
    h[2] = (uint64_t) h2;
    h[3] = (uint64_t) h3;
    h[4] = (uint64_t) h4;
}

