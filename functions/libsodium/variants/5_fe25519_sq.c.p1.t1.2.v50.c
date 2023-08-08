fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_[5];
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t carry, r_[5];

    // Compact into loop
    for(int i=0; i<5; i++){
        f_[i] = (uint128_t) f[i];
    }

    f0_2 = f_[0] << 1;
    f1_2 = f_[1] << 1;

    f1_38 = 38ULL * f_[1];
    f2_38 = 38ULL * f_[2];
    f3_38 = 38ULL * f_[3];

    f3_19 = 19ULL * f_[3];
    f4_19 = 19ULL * f_[4];

    r[0] =   f_[0] * f_[0] + f1_38 * f_[4] + f2_38 * f_[3];
    r[1] = f0_2 * f_[1] + f2_38 * f_[4] + f3_19 * f_[3];
    r[2] = f0_2 * f_[2] +    f_[1] * f_[1] + f3_38 * f_[4];
    r[3] = f0_2 * f_[3] +  f1_2 * f_[2] + f4_19 * f_[4];
    r[4] = f0_2 * f_[4] +  f1_2 * f_[3] +    f_[2] * f_[2];
        
    for(int j=0; j<5; j++){
        r_[j]    = ((uint64_t) r[j]) & mask;
        carry  = (uint64_t) (r[j] >> 51);
        r[(j+1)%5]    += carry;
        r_[j]    = ((uint64_t) r[j]) & mask;
        carry  = (uint64_t) (r[j] >> 51);
        r[(j+1)%5]    += carry;
        r_[j]    = ((uint64_t) r[j]) & mask;
        carry  = (((uint64_t) (r[j] >> 51) ) + 19* ((j==4)?1ULL:0ULL) ) * ((j==4)?1ULL:0ULL);
        r_[((j-1)+5)%5] += 19ULL * carry;
        carry  = r_[((j-1)+5)%5]>> 51;
        r_[((j-1)+5)%5] &= mask;
        r_[j] += carry* (j==0?1ULL:0ULL) ;
    }
            
    // Compact into loop
    for(int i=0; i<5; i++){
        h[i] = r_[i];
    }
}