fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t   r[5], f_19[4], f_val[5], g_val[5];
    uint64_t carry;

    for (int i = 0; i < 5; i++) {
        f_val[i] = (uint128_t) f[i];
        g_val[i] = (uint128_t) g[i];
    }

    f_19[0] = 19ULL * f_val[1]; 
    f_19[1] = 19ULL * f_val[2]; 
    f_19[2] = 19ULL * f_val[3]; 
    f_19[3] = 19ULL * f_val[4]; 

    r[0] = f_val[0]*g_val[0] + f_19[0]*g_val[4] + f_19[1]*g_val[3] + f_19[2]*g_val[2] + f_19[3]*g_val[1];
    r[1] = f_val[0]*g_val[1] +   f_val[1]*g_val[0] + f_19[1]*g_val[4] + f_19[2]*g_val[3] + f_19[3]*g_val[2];
    r[2] = f_val[0]*g_val[2] +   f_val[1]*g_val[1] +   f_val[2]*g_val[0] + f_19[2]*g_val[4] + f_19[3]*g_val[3];
    r[3] = f_val[0]*g_val[3] +   f_val[1]*g_val[2] +   f_val[2]*g_val[1] +   f_val[3]*g_val[0] + f_19[3]*g_val[4];
    r[4] = f_val[0]*g_val[4] +   f_val[1]*g_val[3] +   f_val[2]*g_val[2] +   f_val[3]*g_val[1] +   f_val[4]*g_val[0];

    for (int i = 0; i < 5; i++) {
        r[i] = r[i] & mask;
        carry = r[i] >> 51;
        r[(i+1)%5] = r[(i+1)%5] + carry;
    }

    carry = r[0] >> 51;
    r[0] = r[0] & mask;
    r[1] += carry;
    
    for (int i = 0; i < 5; i++) 
        h[i] = r[i];
}