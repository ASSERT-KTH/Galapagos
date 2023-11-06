fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2 ,tmp1, tmp2, tmp3, tmp4, tmp5;
    uint64_t r[5], carry;
 

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    f0_2 = f0 << 1;
    f1_2 = f1 << 1;

    tmp1 = 38ULL * f1;
    tmp2 = 38ULL * f2;
    tmp3 = 38ULL * f3;

    tmp4 = 19ULL * f3;
    tmp5 = 19ULL * f4;

    r[0] =   f0 * f0 + tmp1 * f4 + tmp2 * f3;
    r[1] = f0_2 * f1 + tmp2 * f4 + tmp4 * f3;
    r[2] = f0_2 * f2 +    f1 * f1 + tmp3 * f4;
    r[3] = f0_2 * f3 +  f1_2 * f2 + tmp5 * f4;
    r[4] = f0_2 * f4 +  f1_2 * f3 +    f2 * f2;

    for (int i = 0; i < 5; i++) 
    {
        r[i]   &= mask; 
        carry   = r[i] >> 51;
        if(i<4) 
            r[i+1] += carry; 
    }
    
    r[0]   += 19ULL * (r[4]>>51);
    for (int i = 0; i < 3; i++) 
    {  
        carry  = (r[i])>>51;
        r[i]   &= mask;
        r[i+1] += carry;       
    }

    for (int i = 0; i < 5; i++) 
        h[i] = r[i];  
}