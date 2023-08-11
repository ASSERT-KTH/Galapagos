fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], fg[5];
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    for(int i = 0; i < 5; i++){
        fg[i] = (uint128_t) f[i] * (i != 0 ? 19ULL : 1);
    }

    r[0] = fg[0]*g[0] + fg[1]*g[4]  + fg[2]*g[3]  + fg[3]*g[2]  + fg[4]*g[1];
    r[1] = fg[0]*g[1] + f[1]*g[0]   + fg[2]*g[4]  + fg[3]*g[3]  + fg[4]*g[2];
    r[2] = fg[0]*g[2] + f[1]*g[1]   + f[2]*g[0]   + fg[3]*g[4]  + fg[4]*g[3];
    r[3] = fg[0]*g[3] + f[1]*g[2]   + f[2]*g[1]   + f[3]*g[0]   + fg[4]*g[4];
    r[4] = fg[0]*g[4] + f[1]*g[3]   + f[2]*g[2]   + f[3]*g[1]   + f[4]*g[0];

    for(int i = 0; i < 5; i++){
        r00    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[(i+1) % 5] += carry;
        r[(i+2) % 5] += carry >= (r00 >> 51) ? 1 : 0;
        r[i] = r00;
    }

    for(int i = 0; i < 5; i++){
        h[i] = r[i];
    }
}