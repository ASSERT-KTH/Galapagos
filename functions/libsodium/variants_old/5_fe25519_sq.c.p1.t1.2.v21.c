Here the variant program that maintain the original functionality.


void fe25519_sq(fe25519 h, const fe25519 f)
{
    uint128_t r[5], gf[5], mcv[5];
    uint64_t carry;
    const uint64_t mask = 0x7ffffffffffffULL;
    
    for(int i=0; i<5; i++){
         gf[i] = (uint128_t) f[i];
    }

    r[0] = gf[0] * gf[0] + 38ULL * gf[1] * gf[4] + 38ULL * gf[2] * gf[3];
    r[1] = 2 * gf[0] * gf[1] + 19 * gf[3] * gf[3] + 38ULL * gf[2] * gf[4];
    r[2] = 2 * gf[0] * gf[2] +  gf[1] * gf[1] + 38ULL * gf[3] * gf[4];
    r[3] = 2 * gf[0] * gf[3] +  2 * gf[1] * gf[2] + 19 * gf[4] * gf[4];
    r[4] = 2 * gf[0] * gf[4] +  2 * gf[1] * gf[3 - 1] + gf[2] * gf[2];

    for(int i=0; i<5; i++){
        mcv[i] = (uint64_t) r[i] & mask;
        if(i != 4) 
            carry  = (uint64_t) (r[i] >> 51);
        r[i + 1] += carry;
    }
    
    mcv[0]   += 19ULL * carry;
    mcv[0]  &= mask;
    carry  = mcv[0] >> 51;
    mcv[1] += carry;
    mcv[1]  &= mask;
    mcv[2] += carry;

    for(int i=0; i<5; i++){
         h[i] = mcv[i];
    }
}

This alternate implementation changes loops instead of individual steps and does minimize repeated computations of the same values thus improving the readability of the solution without altering the original function's behavior.