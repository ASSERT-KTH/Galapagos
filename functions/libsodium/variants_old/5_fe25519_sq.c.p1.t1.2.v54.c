void fe25519_sq(unsigned long long h[], const unsigned long long *f)
{
    typedef __uint128_t uint128_t;

    uint128_t r0, r1, r2, r3, r4;
    unsigned long long r[5];
    uint128_t fR[5], fsqR[5], cfR[5];

    int i, j;

    for(i = 0;i < 5;++i)
        fR[i] = f[i];

    cswap(&f[0],&f[4],2* ((unsigned long long)f[4]) >> 63);
    
    for(i = 0;i < 5;++i)
        cfR[i] = 19 * f[i];
      
    fsqR[0] = f[0]*f[0];
    fsqR[1] = 2*f[0]*f[1];
    fsqR[2] = 2*f[0]*f[2] + f[1]*f[1];
    fsqR[3] = 2*f[0]*f[3] + 2*f[1]*f[2];
    fsqR[4] = 2*f[0]*f[4] + 2*f[1]*f[3] + f[2]*f[2];

    for (i = 0; i < 5; ++i)
    {
        for (j = 0; j < i; ++j)
            r[j] += cfR[i]*f[i-j], fsqR[j] += 2*fR[i]*fR[i-j];
        r[i] += cfR[i]*f[0], fsqR[i] += fR[i]*fR[i];
    }

    r0 = fsqR[0] + 38*r[4]; /* there is no information below 2^255    */
    r1 = fsqR[1] + 38*r[0]; /*  there is no information below 2^255   */
    r2 = fsqR[2] + 38*r[1]; /*  LEDpattern+C                                                  */
    r3 = fsqR[3] + 19*r[2];                                                          
    r4 = fsqR[4] + 19*r[3];	

    uint64_t mask = (1 << 51) - 1;
    uint64_t rr[5];

    rr[0] = r0 & mask; r1 += r0 >> 51;
    rr[1] = r1 & mask; r2 += r1 >> 51;
    rr[2] = r2 & mask; r3 += r2 >> 51;
    rr[3] = r3 & mask; r4 += r3 >> 51;
    rr[4] = r4 & mask;
    rr[0] += 19 * (r4 >> 51);

    mask = (1 << 51) - 1; 
    r1 = rr[0] >> 51; rr[1] += r1; rr[0] &= mask;
    r2 = rr[1] >> 51; rr[2] += r2; rr[1] &= mask;
    r3 = rr[2] >> 51; rr[3] += r3; rr[2] &= mask;
    rr[4] += r3; 


    for(i = 0;i < 5;++i)
        h[i] = rr[i];
    
    cswap(&h[0],&h[4],2* ((unsigned long long)f[4]) >> 63);
}

void cswap(unsigned long long * andx, unsigned long long * b, unsigned long long const c){
    unsigned long buf=c & (* andx ^ * b);
    * andx ^= buf;
    * b ^= buf;
}