void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_multi[5]; 
    uint128_t f_temp[5];
    uint64_t carry;

     for(int i=0;i<5;i++)
        f_temp[i] = (uint128_t) f[i];

    for(int i=0;i<5;i++)
    {
      if(i>=1)
       f_multi[i]= 38ULL * f_temp[i];
      if(i>=3)
       f_multi[i]= 19ULL * f_temp[i];

      if(i<2)
       f_temp[i] = f_temp[i]<<1;

    }

    r[0] = f_temp[0] * f_temp[0] + f_multi[1] + f_multi[2];
    r[1] = f_temp[0] * f_temp[1] + f_multi[2] + f_multi[3];
    r[2] = f_temp[0] * f_temp[2] + f_temp[1] * f_temp[1] + f_multi[3];
    r[3] = f_temp[0] * f_temp[3] + f_temp[1] * f_temp[2] + f_multi[4];
    r[4] = f_temp[0] * f_temp[4] + f_temp[1] * f_temp[3] + f_temp[2] * f_temp[2];

    for(int i=0;i<5;i++)
    {
      h[i]=((uint64_t) r[i]) & mask;
      carry  = (uint64_t) (r[i] >> 51);

      if(i<4)
       r[i+1] += carry;
      else
      {
       h[0] += 19ULL * carry;
       carry     = h[0] >> 51;
       h[0]     &= mask;

       h[1] += carry;
       carry  = h[1] >> 51;
       h[1] &= mask;
       h[2] += carry;
      }
    }
}