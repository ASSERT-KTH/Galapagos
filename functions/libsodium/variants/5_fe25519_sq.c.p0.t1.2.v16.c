fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_prime[5];
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r_prime[5], carry;

    for(int i=0;i<5;++i){
        f_prime[i] = (uint128_t) f[i];
    }

    f0_2 = f_prime[0] << 1;
    f1_2 = f_prime[1] << 1;

    f1_38 = 38ULL * f_prime[1];
    f2_38 = 38ULL * f_prime[2];
    f3_38 = 38ULL * f_prime[3];

    f3_19 = 19ULL * f_prime[3];
    f4_19 = 19ULL * f_prime[4];

    r[0] =   f_prime[0] * f_prime[0] + f1_38 * f_prime[4] + f2_38 * f_prime[3];
    r[1] = f0_2 * f_prime[1] + f2_38 * f_prime[4] + f3_19 * f_prime[3];
    r[2] = f0_2 * f_prime[2] + f_prime[1] * f_prime[1] + f3_38 * f_prime[4];
    r[3] = f0_2 * f_prime[3] +  f1_2 * f_prime[2] + f4_19 * f_prime[4];
    r[4] = f0_2 * f_prime[4] + f1_2 * f_prime[3] + f_prime[2] * f_prime[2];

    for(int i=0;i<5;++i){
        r_prime[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t)  (r[i] >> 51);
        r[(i+1)%5]    += carry;
        r_prime[i]    = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        r[(i+2)%5] += carry;
    }

    for(int i=0;i<5;++i){
        h[i] = r_prime[i];
    }
    
}