fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t fvals[5];
    uint128_t fvals_19[4];
    uint128_t gvals[5];
    uint64_t rvals[5];
    uint64_t carry;

    for(int i=0; i<5; i++){
        fvals[i] = (uint128_t)f[i];
        gvals[i] = (uint128_t)g[i];
        if(i<4) fvals_19[i] = 19ULL*fvals[i+1];
    }

    for(int i=0; i<5; i++){
        r[i] = fvals[0]*gvals[i] + fvals_19[ (i+4)%5 ]*gvals[(i+1)%5] + fvals_19[(i+3)%5]*gvals[(i+2)%5]
             + fvals_19[(i+2)%5]*gvals[(i+3)%5] + fvals_19[(i+1)%5]*gvals[(i+4)%5];
    }

    for(int i=0; i<5; i++){
        rvals[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        r[(i+1)%5] += carry;
    }
  
    rvals[0] += 19ULL * carry;
    for(int i=0; i<5; i++){
         carry  = rvals[i] >> 51;
         rvals[i] &= mask;
         rvals[(i+1)%5] += carry;
    }

    for(int i=0; i<5; i++)
        h[i] = rvals[i];
}
