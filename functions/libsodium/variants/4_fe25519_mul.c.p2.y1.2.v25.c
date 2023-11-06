void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t fs[5], gs[5];
    uint128_t r[5], ftmp, carry;
    const uint64_t mask = 0x7ffffffffffffULL;

    for(int i=0; i<5; ++i)
    {
        fs[i] = (uint128_t) f[i];
        gs[i] = (uint128_t) g[i];
    }

    fs[1] *= 19ULL;
    fs[2] *= 19ULL;
    fs[3] *= 19ULL;
    fs[4] *= 19ULL;

    for(int i=0; i<5; ++i)
    { 
        ftmp = (i>0) ? fs[i-1]/19 : fs[4]*19;
        r[i] = fs[0] * gs[i] + ftmp * gs[ (i-1)%5 ] + fs[ (i+2)%5 ] * gs[ (i-3)%5 ] + fs[ (i+3)%5 ] * gs[ (i-2)%5 ] + fs[ (i+4)%5 ] * gs[ (i-4)%5];
    }
    
    for(int i=0; i<5; i++) {
        h[i]    = (uint64_t) (r[i]) & mask;
        carry  = (uint64_t) (r[i]>>51);
        r[ (i+1)%5 ] += carry;
        if(i<4) h[i] = (uint64_t) (r[i]) & mask;
    }
    carry  = h[0] >> 51;
    h[0]  &= mask;
  	h[1]  += carry;
}
