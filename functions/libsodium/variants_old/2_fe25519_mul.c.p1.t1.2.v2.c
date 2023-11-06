fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_part[5], g_part[5], f19_part[4], r_val[5];
    uint64_t  r[5], carry;

    for (int i = 0; i < 5; i++) {
        f_part[i] = (uint128_t) f[i];
        g_part[i] = (uint128_t) g[i];
    }

    for (int i = 1; i < 5; i++)
        f19_part[i-1] = 19ULL * f_part[i];

    r_val[0] = f_part[0] * g_part[0] + f19_part[0] * g_part[4] + f19_part[1] * g_part[3] + f19_part[2] * g_part[2] + f19_part[3] * g_part[1];
    r_val[1] = f_part[0] * g_part[1] +    f_part[1] * g_part[0] + f19_part[1] * g_part[4] + f19_part[2] * g_part[3] + f19_part[3] * g_part[2];
    r_val[2] = f_part[0] * g_part[2] +    f_part[1] * g_part[1] +    f_part[2] * g_part[0] + f19_part[2] * g_part[4] + f19_part[3] * g_part[3];
    r_val[3] = f_part[0] * g_part[3] +    f_part[1] * g_part[2] +    f_part[2] * g_part[1] +    f_part[3] * g_part[0] + f19_part[3] * g_part[4];
    r_val[4] = f_part[0] * g_part[4] +    f_part[1] * g_part[3] +    f_part[2] * g_part[2] +    f_part[3] * g_part[1] +    f_part[4] * g_part[0];

    for (int i=0; i<5; ++i) {
        r[i]   = ((uint64_t) r_val[i]) & mask;
        carry  = (uint64_t) (r_val[i] >> 51);
        if (i != 4) 
            r_val[i+1] += carry;
    }

    r[0]  += 19ULL * (uint64_t) (r_val[4] >> 51);
    carry = r[0] >> 51;
    r[0]  &= mask;
    r[1]  += carry;
    carry = r[1] >> 51;
    r[1]  &= mask;
    r[2]  += carry;

    for (int i=0; i<5; ++i) 
        h[i] = r[i];
}