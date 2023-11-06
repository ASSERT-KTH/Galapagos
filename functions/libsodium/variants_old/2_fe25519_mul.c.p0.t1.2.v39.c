fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;
    uint128_t f_values[5];

    for(int i=0; i<5; i++){
        f_values[i] = (uint128_t) f[i];
        switch(i){
            case 1: f_values[i] *= 19ULL; break;
            case 2: f_values[i] *= 19ULL; break;
            case 3: f_values[i] *= 19ULL; break;
            case 4: f_values[i] *= 19ULL; break;
        }
    }

    r0 = f_values[0] * g[0] + f_values[1] * g[4] + f_values[2] * g[3] + f_values[3] * g[2] + f_values[4] * g[1];
    r1 =  f[0] * g[1] + f_values[1] * g[0] + f_values[2] * g[4] + f_values[3] * g[3] + g[2]*f_values[4] ;
    r2 =  f[0] * g[2] + f[1] * g[1] + f_values[2] * g[0] + f[0] * g[3]*19ULL + g[3]*f_values[4] ;
    r3 =  f[0] * g[3] + f[1] * g[2] + f[2] * g[1] + f_values[3] * g[0] + g[4]*f_values[4] ;
    r4 =  f_values[0] * g[4] + f[1] * g[3] + g[2]*f_values[2] + f[3] * g[1] + f_values[4] * g[0] ;

    r00    = ((uint64_t) r0) & mask;
    carry  = (uint64_t) (r0 >> 51);
    r1    += carry;
    r01    = ((uint64_t) r1) & mask;
    carry  = ((uint64_t) r1 >> 51);
    r2    += carry;
    r02    = ((uint64_t) r2) & mask;
    carry  = ((uint64_t) r2 >> 51);
    r3    += carry;
    r03    = ((uint64_t) r3) & mask;
    carry  = ((uint64_t) r3 >> 51);
    r4    += carry;
    r04    = (uint64_t)(r4 & mask);
    carry  = ((uint64_t) r4 >> 51);
    r00   += 19ULL * carry;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    r01   &= (carry << 51) - 1;
    r02   += (uint64_t) (r1 >> 51);

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}