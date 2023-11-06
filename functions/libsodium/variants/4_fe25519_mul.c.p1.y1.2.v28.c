Variant 1:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_[5], g_[5], f19[4];
    uint64_t  r_[5], carry;
    int i;

    for(i = 0; i < 5; i++){
        f_[i] = (uint128_t) f[i];
        g_[i] = (uint128_t) g[i];
        if(i < 4) f19[i] = 19ULL * f_[i + 1];
    }

    r[0] = f_[0] * g_[0] + f19[0] * g_[4] + f19[1] * g_[3] + f19[2] * g_[2] + f19[3] * g_[1];
    r[1] = f_[0] * g_[1] + f_[1] * g_[0] + f19[1] * g_[4] + f19[2] * g_[3] + f19[3] * g_[2];
    r[2] = f_[0] * g_[2] + f_[1] * g_[1] + f_[2] * g_[0] + f19[2] * g_[4] + f19[3] * g_[3];
    r[3] = f_[0] * g_[3] + f_[1] * g_[2] + f_[2] * g_[1] + f_[3] * g_[0] + f19[3] * g_[4];
    r[4] = f_[0] * g_[4] + f_[1] * g_[3] + f_[2] * g_[2] + f_[3] * g_[1] + f_[4] * g_[0];

    r_[0]    = r[0] & mask;
    for(i = 0; i < 4; i++) {
        carry  = r[i] >> 51;
        r_[i+1] = (r[i+1] + carry) & mask;
    }

    carry  = r[4] >> 51;
    r_[0] += 19ULL * carry;
    carry  = r_[0] >> 51;
    r_[0] &= mask;
    
    r_[1] += carry;
    carry  = r_[1] >> 51;
    r_[1] &= mask;

    r_[2] += carry;

    for(i = 0; i < 5; i++) {
        h[i] = r_[i];
    }
}

Variant 2:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g){
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r_[5] = {0}, a[4] = {19ULL * f[1], 19ULL * f[2], 19ULL * f[3], 19ULL * f[4]};
    uint64_t  r[5], carry;
    int i;

    r_[0] = f[0] * g[0] + a[0] * g[4] + a[1] * g[3] + a[2] * g[2] + a[3] * g[1];
    r_[1] = f[0] * g[1] + f[1] * g[0] + a[1] * g[4] + a[2] * g[3] + a[3] * g[2];
    r_[2] = f[0] * g[2] + f[1] * g[1] + f[2] * g[0] + a[2] * g[4] + a[3] * g[3];
    r_[3] = f[0] * g[3] + f[1] * g[2] + f[2] * g[1] + f[3] * g[0] + a[3] * g[4];
    r_[4] = f[0] * g[4] + f[1] * g[3] + f[2] * g[2] + f[3] * g[1] + f[4] * g[0];

    r[0]    = r_[0] & mask;
    for(i = 0; i < 4; i++) {
        carry  = r_[i] >> 51;
        r[i+1] = (r_[i+1] + carry) & mask;
    }

    carry  = r_[4] >> 51;
    r[0] += 19ULL * carry;
    carry  = r[0] >> 51;
    r[0] &= mask;
    
    r[1] += carry;
    carry  = r[1] >> 51;
    r[1] &= mask;

    r[2] += carry;

    for(i = 0; i < 5; i++) {
        h[i] = r[i];
    }
}
