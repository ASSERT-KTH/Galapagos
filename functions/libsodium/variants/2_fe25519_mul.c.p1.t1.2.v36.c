fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_var[5], g_var[5];
    uint128_t f19[4];
    uint64_t r_var[5], carry;

    for(int i=0; i<5; i++){
        f_var[i] = (uint128_t) f[i];
        g_var[i] = (uint128_t) g[i];
    }

    for(int i=1; i< 5; i++)
        f19[i-1] = 19ULL * f_var[i];

    r[0] = f_var[0] * g_var[0] + f19[0] * g_var[4] + f19[1] * g_var[3] + f19[2] * g_var[2] + f19[3] * g_var[1];
    r[1] = f_var[0] * g_var[1] + f_var[1] * g_var[0] + f19[1] * g_var[4] + f19[2] * g_var[3] + f19[3] * g_var[2];
    r[2] = f_var[0] * g_var[2] + f_var[1] * g_var[1] + f_var[2] * g_var[0] + f19[2] * g_var[4] + f19[3] * g_var[3];
    r[3] = f_var[0] * g_var[3] + f_var[1] * g_var[2] + f_var[2] * g_var[1] + f_var[3] * g_var[0] + f19[3] * g_var[4];
    r[4] = f_var[0] * g_var[4] + f_var[1] * g_var[3] + f_var[2] * g_var[2] + f_var[3] * g_var[1] + f_var[4] * g_var[0];

    for(int i=0; i<5; i++) {
        r_var[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r_var[ (i+1)%5 ]    += carry;
    }

    r_var[0]   += 19ULL * carry;
    carry  = r_var[0] >> 51;
    r_var[0]   &= mask;
    r_var[1]   += carry;
    carry  = r_var[1] >> 51;
    r_var[1]   &= mask;
    r_var[2]   += carry;

    for(int i = 0; i<5; i++)
        h[i] = r_var[i];
}