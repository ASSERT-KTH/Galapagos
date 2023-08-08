fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_cast[5];
    uint128_t g_cast[5];
    uint128_t f_mul[4];
    uint64_t  r_final[5];
    uint64_t  carry;

    for (int i = 0; i < 5; i++) {
        f_cast[i] = (uint128_t) f[i];
        g_cast[i] = (uint128_t) g[i];
    }

    for (int i = 1; i < 5; i++) {
        f_mul[i-1] = 19ULL * f_cast[i];
    }

    r[0] = f_cast[0]*g_cast[0] + f_mul[0]*g_cast[4] + f_mul[1]*g_cast[3] + f_mul[2]*g_cast[2] + f_mul[3]*g_cast[1];
    r[1] = f_mul[0]*g_cast[0] + f_mul[0]*g_cast[4] + f_mul[1]*g_cast[3] + f_mul[2]*g_cast[2] + f_mul[3]*g_cast[1] + f_cast[0]*g_cast[1];
    r[2] = f_cast[0]*g_cast[2] + f_cast[1]*g_cast[1] + f_cast[2]*g_cast[0] + f_mul[2]*g_cast[4] + f_mul[3]*g_cast[3];
    r[3] = f_cast[0]*g_cast[3] + f_cast[1]*g_cast[2] + f_cast[2]*g_cast[1] + f_cast[3]*g_cast[0] + f_mul[3]*g_cast[4];
    r[4] = f_cast[0]*g_cast[4] + f_cast[1]*g_cast[3] + f_cast[2]*g_cast[2] + f_cast[3]*g_cast[1] + f_cast[4]*g_cast[0];

    for (int i = 0; i < 5; i++) { 
        r_final[i] = ((uint64_t) r[i]) & mask;
        if (i != 4) {
            carry = (uint64_t) (r[i] >> 51);
            r_final[i+1] += carry;
        }
    }

    carry = r_final[4] >> 51;
    r_final[4] &= mask;
    carry *= 19ULL;
    r_final[0] += carry;
    carry  = r_final[0] >> 51;
    r_final[0] &= mask;
    r_final[1] += carry;
    carry  = r_final[1] >> 51;
    r_final[1] &= mask;
    r_final[2] += carry;

    for (int i = 0; i < 5; i++) {
        h[i] = r_final[i];
    }
}
