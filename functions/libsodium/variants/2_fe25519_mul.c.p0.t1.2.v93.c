fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g){
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;
    uint128_t g[5] = {0}, f[5] = {0};

    for(int i = 0; i < 5; i++){
        f[i] = (uint128_t)f[i];
        g[i] = (uint128_t)g[i];
    }

    uint128_t tmp_f[4];
    for(int i = 1; i <= 4; i++)
        tmp_f[i-1] = 19ULL * f[i];

    r0 = f[0] * g[0] + tmp_f[3] * g[4] + tmp_f[2] * g[3] + tmp_f[1] * g[2] + tmp_f[0] * g[1];
    r1 = f[0] * g[1] +    f[1] * g[0] + tmp_f[3] * g[4] + tmp_f[2] * g[3] + tmp_f[0] * g[2];
    r2 = f[0] * g[2] +    f[1] * g[1] +    f[2] * g[0] + tmp_f[3] * g[4] + tmp_f[1] * g[3];
    r3 = f[0] * g[3] +    f[1] * g[2] +    f[2] * g[1] +    f[3] * g[0] + tmp_f[3] * g[4];
    r4 = f[0] * g[4] +    f[1] * g[3] +    f[2] * g[2] +    f[3] * g[1] +    f[4] * g[0];

    r00 = (r0 & mask);
    carry  = (r0 >> 51);
    r1    += carry;
    r01 = (r1 & mask);
    carry  = (r1 >> 51);
    r2    += carry;
    r02 = (r2 & mask);
    carry  = (r2 >> 51);
    r3    += carry;
    r03 = (r3 & mask);
    carry  = (r3 >> 51);
    r4    += carry;
    r04 = (r4 & mask);
    carry  = (r4 >> 51);
    r00   += 19ULL * carry;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    r02   += carry;
     
    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}