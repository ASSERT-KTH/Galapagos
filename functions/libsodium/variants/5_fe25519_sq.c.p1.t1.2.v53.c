
fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f_t2[2], f_tm19[2], f_tm38[3];
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    f_t2[0] = f0 << 1;
    f_t2[1] = f1 << 1;

    f_tm38[0] = 38ULL * f1;
    f_tm38[1]= 38ULL * f2;
    f_tm38[2] = 38ULL * f3;

    f_tm19[0] = 19ULL * f3;
    f_tm19[1]= 19ULL * f4;

    r[0] =   f0 * f0 + f_tm38[0] * f4 + f_tm38[1] * f3; 
    r[1] = f_t2[0] * f1 + f_tm38[1] * f4 + f_tm19[0] * f3;
    r[2] =  f_t2[0] * f2  +    f1 * f1 + f_tm38[2] * f4; 
    r[3] =  f_t2[0] * f3 +  f_t2[1] * f2 + f_tm19[1] * f4;
    r[4] =  f_t2[0] * f4 +  f_t2[1] * f3 +    f2 * f2; 

    for(int i = 0; i < 5; ++i){
        h[i] = (((uint64_t) r[i]) & mask);
        carry = (uint64_t) (r[i] >> 51);
        
        if(i+1 < 5) //prevent overflowing of 'r[i+1]', update r[i+1] unless 'r[i]' is 'r[4]'.
            r[i+1] += carry;
    }
    

    h[0]+= 19ULL * carry;
    carry = h[0] >> 51;
    h[0] &= mask;

    for(int  j = 1; j < 3; ++j){
        h[j] += carry;
        carry = h[j] >> 51;
        h[j] &= mask;
    }

}
