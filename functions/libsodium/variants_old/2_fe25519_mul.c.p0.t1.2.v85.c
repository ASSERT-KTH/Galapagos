fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f_elements[5];
    uint128_t g_elements[5];
    uint64_t  r_elements[5];
    uint64_t  carry;
    uint64_t idx;

    for(idx=0; idx<5; idx++)
    {
        f_elements[idx] = (uint128_t) f[idx];
        g_elements[idx] = (uint128_t) g[idx];
    }

    r0 = f_elements[0] * g_elements[0] + 19ULL * f_elements[1] * g_elements[4] + 19ULL * f_elements[2] * g_elements[3] + 19ULL * f_elements[3] * g_elements[2] + 19ULL * f_elements[4] * g_elements[1];
    r1 = f_elements[0] * g_elements[1] + f_elements[1] * g_elements[0] + 19ULL * f_elements[2] * g_elements[4] + 19ULL * f_elements[3] * g_elements[3] + 19ULL * f_elements[4] * g_elements[2];
    r2 = f_elements[0] * g_elements[2] + f_elements[1] * g_elements[1] + f_elements[2] * g_elements[0] + 19ULL * f_elements[3] * g_elements[4] + 19ULL * f_elements[4] * g_elements[3];
    r3 = f_elements[0] * g_elements[3] + f_elements[1] * g_elements[2] + f_elements[2] * g_elements[1] + f_elements[3] * g_elements[0] + 19ULL * f_elements[4] * g_elements[4];
    r4 = f_elements[0] * g_elements[4] + f_elements[1] * g_elements[3] + f_elements[2] * g_elements[2] + f_elements[3] * g_elements[1] + f_elements[4] * g_elements[0];

    r_elements[0]  = ((uint64_t) r0) & mask;
    carry  = (uint64_t) (r0 >> 51);
    r1    += carry;
    r_elements[1]  = ((uint64_t) r1) & mask;
    carry  = (uint64_t) (r1 >> 51);
    r2    += carry;
    r_elements[2]  = ((uint64_t) r2) & mask;
    carry  = (uint64_t) (r2 >> 51);
    r3    += carry;
    r_elements[3]  = ((uint64_t) r3) & mask;
    carry  = (uint64_t) (r3 >> 51);
    r4    += carry;
    r_elements[4]  = ((uint64_t) r4) & mask;
    carry  = (uint64_t) (r4 >> 51);
    r_elements[0] += 19ULL * carry;
    carry  = r_elements[0] >> 51;
    r_elements[0]  &= mask;
    r_elements[1]   += carry;
    carry  = r_elements[1] >> 51;
    r_elements[1]  &= mask;
    r_elements[2]  += carry;

    for(idx=0; idx<5; idx++)
    {
        h[idx] = r_elements[idx];
    }
}