fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r_temp[5];
    uint128_t f_temp[5], f_19[5];
    uint128_t g_temp[5];
    uint64_t  result_temp[5], carry;

    for(int i=0; i<5; i++)
    {
        f_temp[i] = (uint128_t) f[i];
        g_temp[i] = (uint128_t) g[i];
        
        if(i>0)
            f_19[i] = 19ULL * f_temp[i];
    }
  
    r_temp[0] = f_temp[0] * g_temp[0] + f_19[1] * g_temp[4] + f_19[2] * g_temp[3] + f_19[3] * g_temp[2] + f_19[4] * g_temp[1];
    r_temp[1] = f_temp[0] * g_temp[1] +                       
                 f_temp[1] * g_temp[0] +                       
                 f_19[2] * g_temp[4] +                          
                 f_19[3] * g_temp[3] +                          
                 f_19[4] * g_temp[2];
    r_temp[2] = f_temp[0] * g_temp[2] +                       
                f_temp[1] * g_temp[1] +                       
                f_temp[2] * g_temp[0] +                       
                f_19[3] * g_temp[4] +                          
                f_19[4] * g_temp[3];
    r_temp[3] = f_temp[0] * g_temp[3] +                       
                 f_temp[1] * g_temp[2] +                       
                 f_temp[2] * g_temp[1] +                       
                 f_temp[3] * g_temp[0] +                       
                 f_19[4] * g_temp[4];
    r_temp[4] = f_temp[0] * g_temp[4] +                       
                 f_temp[1] * g_temp[3] +                       
                 f_temp[2] * g_temp[2] +                       
                 f_temp[3] * g_temp[1] +                       
                 f_temp[4] * g_temp[0];

   for(int i=0;i<5;i++)
   {
        result_temp[i]  = ((uint64_t) r_temp[i]) & mask;
        carry  = (uint64_t) (r_temp[i] >> 51);
        if(i<4) {
            r_temp[i+1] += carry;
            result_temp[i+1] = ((uint64_t) r_temp[i+1]) & mask;
        }
        result_temp[i] += 19ULL * carry;
        carry  = result_temp[i] >> 51;
        result_temp[i] &= mask;
        if(i<2)
            result_temp[i+2] += carry;
   }

   for(int i=0;i<5;i++)
        h[i] = result_temp[i];
}