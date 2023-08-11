fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_5[5], g_5[5];
    uint128_t f_01_04_19[4];
    uint64_t  r_carry[5];
    uint64_t  carry;

    for (int i=0; i<5; i++)
    {
        f_5[i] = (uint128_t) f[i];
        g_5[i] = (uint128_t) g[i];
    }

    for (int i=1; i<5; i++)  // calculate f1-4 * 19
        f_01_04_19[i-1] = 19ULL * f_5[i];

    r[0] = f_5[0] * g_5[0] + f_01_04_19[3] * g_5[4] + f_01_04_19[2] * g_5[3] + f_01_04_19[1] * g_5[2] + f_01_04_19[0]*g_5[1];
    r[1] = f_5[0] * g_5[1] + f_5[1] * g_5[0] + f_01_04_19[2] * g_5[4] + f_01_04_19[1] * g_5[3] + f_01_04_19[0]*g_5[2];
    r[2] = f_5[0] * g_5[2] + f_5[1] * g_5[1] + f_5[2] * g_5[0] + f_01_04_19[1] * g_5[4] + f_01_04_19[0]*g_5[3];
    r[3] = f_5[0] * g_5[3] + f_5[1] * g_5[2] + f_5[2] * g_5[1] + f_5[3] * g_5[0] + f_01_04_19[0]*g_5[4];
    r[4] = f_5[0] * g_5[4] + f_5[1] * g_5[3] + f_5[2] * g_5[2] + f_5[3] * g_5[1] + f_5[4]*g_5[0];

    for (int i=0; i<5; i++)  
    {
      r_carry[i]    = ((uint64_t)r[i]) & mask;
      carry  = (uint64_t) (r[i] >> 51);
      r[(i+1)%5]    += carry;
      r_carry[(i+1)%5]    = ((uint64_t) r[(i+1)%5]) & mask;
      carry  = (uint64_t) (r[(i+1)%5] >> 51);
      r_carry[(i+2)%5]    += carry;
      r_carry[(i+2)%5]   &= mask;
    }

    for (int i=0; i<5; i++)  
      h[i] = r_carry[i];
}