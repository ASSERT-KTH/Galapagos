
void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t r[5] = {0};
    uint64_t r_tmp[5] = {0};
    uint64_t carry = 0;
    uint64_t f_2_38[5] = {0}, f_2[5]={0}, f_zech[5]={19*f[3], 2*f[1], 38*f[2], 2*f[3], 2*f[4]};
    int i = 0, j = 0;

    for(i=0;i<5;i++){
        f_2_38[i]=38*f[i];
        f_2[i]= f[i]<<1;
    }


    uint64_t product_result_zech[15] = 
      {0,      f_2_38[4], f_2_38[3],
      f_zech[1], f_2_38[4], 19*f[3],
      f_2_38[2], f_2[1],     f_2_38[4],
      f_zech[3], f_2[2],     19*f[4],
      f[4]<<1,   f_zech[4], f[2]<<1};

    for(i=0;i<5;i++)
    for(j=0;j<=i;j++)
    {
        __uint128_t product = (__uint128_t)f[i]*f[j];
        if(i != j) product <<= 1;
        r_tmp[i+j] = (uint64_t)(product) & mask;
        r_tmp[i+j+1] = (uint64_t)(product >> 51);
        r[i] += product_result_zech[i*3+j];
    }

    for(j=0;j<5;j++)
        {
            r[j] += carry + r_tmp[j];
	        carry = r[j] >> 51;
            r[j] &= mask;
        }
    r[0]+=19*carry;

    h[0] = r[0]; h[1] = r[1];
    h[2] = r[2]; h[3] = r[3];
    h[4] = r[4];

}
