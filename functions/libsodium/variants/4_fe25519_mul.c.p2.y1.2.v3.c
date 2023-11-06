void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t  carry;
    uint128_t r[5], f_f[5], g_f[5];

    for (int i=0; i<5; i++){
        f_f[i] = (uint128_t)f[i];
        g_f[i] = (uint128_t)g[i];
    }
    
    uint128_t multiples[4] = {19 * f_f[1], 19 * f_f[2], 19 * f_f[3], 19 * f_f[4]};

    r[0] = f_f[0] * g_f[0] + multiples[0] * g_f[4] + multiples[1] * g_f[3] + multiples[2] * g_f[2] + multiples[3] * g_f[1];
    r[1] = f_f[0] * g_f[1] +     f_f[1] * g_f[0] + multiples[1] * g_f[4] + multiples[2] * g_f[3] + multiples[3] * g_f[2];
    r[2] = f_f[0] * g_f[2] +     f_f[1] * g_f[1] +     f_f[2] * g_f[0] + multiples[2] * g_f[4] + multiples[3] * g_f[3];
    r[3] = f_f[0] * g_f[3] +     f_f[1] * g_f[2] +     f_f[2] * g_f[1] +     f_f[3] * g_f[0] + multiples[3] * g_f[4];
    r[4] = f_f[0] * g_f[4] +     f_f[1] * g_f[3] +     f_f[2] * g_f[2] +     f_f[3] * g_f[1] +     f_f[4] * g_f[0];
    
    for(int i =0; i< 4; i++){
        h[i] = ((uint64_t)r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
    }
    h[4] = ((uint64_t)r[4]) & mask;
   
    carry  = (uint64_t) (r[4] >> 51);
    h[0] += 19ULL * carry;
    
    for(int i=0; i<2; i++){
        carry = h[i] >> 51;
        h[i] &= mask;
        h[i+1] += carry;
    }

}