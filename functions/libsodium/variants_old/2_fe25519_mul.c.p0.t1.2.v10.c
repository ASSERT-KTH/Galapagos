fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_cast[5], f_19[4], g_cast[5];
    uint64_t  r_carry[5],  r_mask[5];
    uint64_t  carry;

    for(int i = 0; i < 5; i++)
        f_cast[i] = (uint128_t)f[i];

    for(int i = 0; i < 5; i++)
        g_cast[i] = (uint128_t)g[i];

    for(int i = 1; i < 5; i++)
        f_19[i-1] = 19ULL * f_cast[i];

    r[0] = f_cast[0]*g_cast[0]       + f_19[0]*g_cast[4] + f_19[1]*g_cast[3] + f_19[2]*g_cast[2] + f_19[3]*g_cast[1];
    r[1] = f_cast[0]*g_cast[1] + f_cast[1]*g_cast[0] + f_19[1]*g_cast[4] + f_19[2]*g_cast[3] + f_19[3]*g_cast[2];

    for(int i = 2; i < 5; i++)
        r[i] = f_cast[0]*g_cast[i] + f_cast[1]*g_cast[i-1] + t_cast[2]*g_cast[i-2] + f[i]*g[5-i] + f[5-i]*g[0];

    for(int i = 0; i < 5; i++){
        r_mask[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        r[(i+1)%5] += carry;
        r_carry[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
    }

    r_mask[0] += 19ULL * carry;

    for(int i = 0; i  < 5; i++) {
        carry = r_mask[i] >> 51;
        r_mask[i] &= mask;
        r_mask[(i+1)%5] += carry;
    }

    for(int i = 0; i < 5; i++)
        h[i] = r_mask[i];
}
