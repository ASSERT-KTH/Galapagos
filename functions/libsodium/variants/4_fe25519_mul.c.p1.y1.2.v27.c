Variant 1:


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_[5];
    uint128_t f_19[4];
    uint128_t g_[5];
    uint64_t  r_[5];
    uint64_t  carry;

    for (uint64_t i = 0; i < 5; i++) {
        f_[i] = f[i];
        g_[i] = g[i];
    }

    for (uint64_t i = 1; i < 5; i++) {
        f_19[i-1] = 19ULL * f_[i];
    }
    
    r[0] = f_[0] * g_[0] + f_19[3] * g_[4] + f_19[2] * g_[3] + f_19[1] * g_[2] + f_19[0] * g_[1];
    r[1] = f_[0] * g_[1] +   f_[1] * g_[0] + f_19[3] * g_[4] + f_19[2] * g_[3] + f_19[1] * g_[2];
    r[2] = f_[0] * g_[2] +   f_[1] * g_[1] +   f_[2] * g_[0] + f_19[3] * g_[4] + f_19[2] * g_[3];
    r[3] = f_[0] * g_[3] +   f_[1] * g_[2] +   f_[2] * g_[1] +    f_[3] * g_[0] + f_19[3] * g_[4];
    r[4] = f_[0] * g_[4] +   f_[1] * g_[3] +   f_[2] * g_[2] +    f_[3] * g_[1] +    f_[4] * g_[0];

    for (uint64_t i = 0; i < 5; i++) {
        r_[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        if (i < 4) {
          r[i+1] += carry;
        }
        else {
           r_[0] += 19ULL * carry;
        }
        carry  = r_[0] >> 51;
        r_[i]   &= mask;
        if (i < 3) {
            r_[i+1] += carry;
        }
    }

    for (uint64_t i = 0; i < 5; i++) {
        h[i] = r_[i];
    }
}


Variant 2:


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
   const uint64_t mask = 0x7ffffffffffffULL;
   uint128_t r[5] = {0};
   uint128_t f1_std, f2_std, f3_std, f4_std;
   uint64_t carry;

   f1_std = ((uint128_t)19) * f[1];
   f2_std = ((uint128_t)19) * f[2];
   f3_std = ((uint128_t)19) * f[3];
   f4_std = ((uint128_t)19) * f[4];
   
   for(uint8_t i= 0; i< 5; i++) {
       r[0] += f[i]*g[(5-i)%5];
       r[1] += f[i]*g[(6-i)%5];
       r[2] += f[i]*g[(7-i)%5];
       r[3] += f[i]*g[(8-i)%5];
       r[4] += f[i]*g[(9-i)%5];
   } 
   r[0] += f1_std * g[4] + f2_std * g[3] + f3_std * g[2] + f4_std * g[1];
   r[1] += f1_std * g[0] + f2_std * g[4] + f3_std * g[3] + f4_std * g[2];
   r[2] += f1_std * g[1] + f2_std * g[0] + f3_std * g[4] + f4_std * g[3];
   r[3] += f1_std * g[2] + f2_std * g[1] + f3_std * g[0] + f4_std * g[4];
   r[4] += f1_std * g[3] + f2_std * g[2] + f3_std * g[1] + f4_std * g[0];

   for(uint8_t i= 0; i< 5; i++) {
       h[i]    = r[i] & mask;
       carry  = r[i] >> 51;
       if(i < 4)
           r[i+1] += carry;
       else
           r[0] += carry * 19;
   }
   for(uint8_t i= 0; i< 4; i++) {
    carry  = h[i] >> 51;
    h[i]  &= mask;
    h[i+1]+= carry;
   } 
}
