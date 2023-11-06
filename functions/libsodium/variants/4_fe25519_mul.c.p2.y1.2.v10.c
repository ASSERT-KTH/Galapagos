fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_new[5], g_new[5], fvalues[5];
    uint64_t  rvalues[5], carry, i;

    for(i = 0; i < 5; ++i) {
        f_new[i] = (uint128_t) f[i];
        g_new[i] = (uint128_t) g[i];

        if(i > 0)
           fvalues[i] = 19ULL * f_new[i];
    }

    r[0] = f_new[0] * g_new[0] + fvalues[1] * g_new[4] + fvalues[2] * g_new[3] + fvalues[3] * g_new[2] + fvalues[4] * g_new[1];
    r[1] = f_new[0] * g_new[1] +    f_new[1] * g_new[0] + fvalues[2] * g_new[4] + fvalues[3] * g_new[3] + fvalues[4] * g_new[2];
    r[2] = f_new[0] * g_new[2] +    f_new[1] * g_new[1] +    f_new[2] * g_new[0] + fvalues[3] * g_new[4] + fvalues[4] * g_new[3];
    r[3] = f_new[0] * g_new[3] +    f_new[1] * g_new[2] +    f_new[2] * g_new[1] +    f_new[3] * g_new[0] + fvalues[4] * g_new[4];
    r[4] = f_new[0] * g_new[4] +    f_new[1] * g_new[3] +    f_new[2] * g_new[2] +    f_new[3] * g_new[1] +    f_new[4] * g_new[0];

    for(i = 0; i < 5; ++i) {
        rvalues[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        
        if(i < 4){
          r[i+1] += carry;
        } else if(i == 4) {           
          rvalues[0] += 19ULL * carry;
          carry  = rvalues[0] >> 51;
          rvalues[0] &= mask;
          rvalues[1] += carry;
          carry  = rvalues[1] >> 51;
          rvalues[1] &= mask;
          rvalues[2] += carry;
        } 
    }

    for(i = 0; i < 5; ++i)
       h[i] = rvalues[i];
}