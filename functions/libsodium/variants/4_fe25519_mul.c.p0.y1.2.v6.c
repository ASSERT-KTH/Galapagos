void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t carry;
    uint128_t c0, c1, c2, c3, c4;
    uint128_t h_temp[5];
    uint128_t f_val[5], g_val[5];

    for(int i=0; i<5; i++) {
        f_val[i] = (uint128_t) f[i];
        g_val[i] = (uint128_t) g[i];
    }

    c0 = f_val[0];
    c1 = 19ULL * f_val[1];
    c2 = 19ULL * f_val[2];
    c3 = 19ULL * f_val[3];
    c4 = 19ULL * f_val[4];

    h_temp[0] = c0 * g_val[0] + c1 * g_val[4] + c2 * g_val[3] + c3 * g_val[2] + c4 * g_val[1];
    h_temp[1] = f_val[0] * g_val[1] + f_val[1] * g_val[0] + c1 * g_val[3] + c2 * g_val[2] + c3 * g_val[1];
    h_temp[2] = f_val[0] * g_val[2] + f_val[1] * g_val[1] + f_val[2] * g_val[0] + c0 * g_val[3] + c1 * g_val[2];
    h_temp[3] = f_val[0] * g_val[3] + f_val[1] * g_val[2] + f_val[2] * g_val[1] + f_val[3] * g_val[0] + c0 * g_val[1];
    h_temp[4] = f_val[0] * g_val[4] + f_val[1] * g_val[3] + f_val[2] * g_val[2] + f_val[3] * g_val[1] + f_val[4] * g_val[0];

    for(int i=0; i<4; ++i) {
        h_temp[i + 1] += (uint64_t) (h_temp[i] >> 51);
        h[i] = ((uint64_t) h_temp[i]) & mask;
    }

    carry = h_temp[4] >> 51;
    h_temp[0] += 19ULL * carry;
    h[4] = h_temp[4] & mask;
    
    carry = h_temp[0] >> 51;
    carry &= mask;
    h[0] += carry;
    carry = h_temp[1] >> 51;
    h[0] += 19ULL * carry;
    h[1] += (uint64_t) (h_temp[1]) & mask;
}
