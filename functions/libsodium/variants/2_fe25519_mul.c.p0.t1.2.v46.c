fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_eff[5], g_eff[5];
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint64_t  r_eff[5];
    uint64_t  carry;

    for(int i=0; i<5; i++){
        f_eff[i] = (uint128_t) f[i];
        g_eff[i] = (uint128_t) g[i];
    }

    f1_19 = 19ULL * f_eff[1];
    f2_19 = 19ULL * f_eff[2];
    f3_19 = 19ULL * f_eff[3];
    f4_19 = 19ULL * f_eff[4];

    r[0] = f_eff[0] * g_eff[0] + f1_19 * g_eff[4] + f2_19 * g_eff[3] + f3_19 * g_eff[2] + f4_19 * g_eff[1];
    r[1] = f_eff[0] * g_eff[1] + f_eff[1] * g_eff[0] + f2_19 * g_eff[4] + f3_19 * g_eff[3] + f4_19 * g_eff[2];
    r[2] = f_eff[0] * g_eff[2] + f_eff[1] * g_eff[1] + f_eff[2] * g_eff[0] + f3_19 * g_eff[4] + f4_19 * g_eff[3];
    r[3] = f_eff[0] * g_eff[3] + f_eff[1] * g_eff[2] + f_eff[2] * g_eff[1] + f_eff[3] * g_eff[0] + f4_19 * g_eff[4];
    r[4] = f_eff[0] * g_eff[4] + f_eff[1] * g_eff[3] + f_eff[2] * g_eff[2] + f_eff[3] * g_eff[1] + f_eff[4] * g_eff[0];

    for(int i=0; i<5; i++){
        r_eff[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        if(i<4)
          r[i+1] += carry;
    }

    r_eff[0] += 19ULL * carry;
    carry = r_eff[0] >> 51;
    r_eff[0] &= mask;
    r_eff[1] += carry;
    carry = r_eff[1] >> 51;
    r_eff[1] &= mask;
    r_eff[2] += carry;

    for(int i=0; i<5; i++) h[i] = r_eff[i];
}