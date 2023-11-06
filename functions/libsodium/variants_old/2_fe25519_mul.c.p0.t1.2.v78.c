fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0to4[5], f0to4[5], f1to4_mul19[4], g0to4[5];
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    for (int i = 0; i < 5; ++i) {
        f0to4[i] = (uint128_t) f[i];
        g0to4[i] = (uint128_t) g[i];
    }

    for (int i = 1; i < 5; ++i) {
        f1to4_mul19[i-1] = 19ULL * f0to4[i];
    }   

    r0to4[0] = f0to4[0]*g0to4[0] + f1to4_mul19[0]*g0to4[4] + f1to4_mul19[1]*g0to4[3] + f1to4_mul19[2]*g0to4[2] + f1to4_mul19[3]*g0to4[1];
    r0to4[1] = f0to4[0]*g0to4[1] + f0to4[1]*g0to4[0] + f1to4_mul19[1]*g0to4[4] + f1to4_mul19[2]*g0to4[3] + f1to4_mul19[3]*g0to4[2];
    r0to4[2] = f0to4[0]*g0to4[2] + f0to4[1]*g0to4[1] + f0to4[2]*g0to4[0] + f1to4_mul19[2]*g0to4[4] + f1to4_mul19[3]*g0to4[3];
    r0to4[3] = f0to4[0]*g0to4[3] + f0to4[1]*g0to4[2] + f0to4[2]*g0to4[1] + f0to4[3]*g0to4[0] + f1to4_mul19[3]*g0to4[4];
    r0to4[4] = f0to4[0]*g0to4[4] + f0to4[1]*g0to4[3] + f0to4[2]*g0to4[2] + f0to4[3]*g0to4[1] +     f0to4[4]*g0to4[0];

    for (int i = 0; i < 5; ++i) {
        r0to4[i+1] +=  (uint64_t) (r0to4[i] >> 51); 
        h[i] = ((uint64_t) r0to4[i]) & mask; 
    }

    r00    = h[0];
    r01    = h[1];
    r02    = h[2];
    r03    = h[3];
    r04    = h[4];

    r00 += 19ULL * ((uint64_t) (r0to4[4] >> 51)); // add carry from 4th element scaling by 19ULL
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