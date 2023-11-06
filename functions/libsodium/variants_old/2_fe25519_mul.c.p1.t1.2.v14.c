fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_elements[5], g_elements[5];
    uint128_t multiplied_elements[5];
    uint128_t multiplied_19[4];
    uint64_t  result_elements[5];

    for (int i = 0; i < 5; i++)
    {
        f_elements[i] = (uint128_t)f[i];
        g_elements[i] = (uint128_t)g[i];
    }

    for (int i = 1; i <= 4; i++)
    {
        multiplied_19[i-1] = 19ULL * f_elements[i];
    }

    multiplied_elements[0] = f_elements[0]*g_elements[0] + multiplied_19[3]*g_elements[4] + multiplied_19[2]*g_elements[3] + multiplied_19[1]*g_elements[2] + multiplied_19[0]*g_elements[1];
    result_elements[0] = ((uint64_t) multiplied_elements[0]) & mask;
    uint64_t  carry =  (uint64_t)(multiplied_elements[0] >> 51);

    for (int i = 1; i < 5; i++) 
    {
        multiplied_elements[i] = f_elements[0]*g_elements[i] + f_elements[i]*g_elements[0] + 
               i < 4 ? multiplied_19[3]*g_elements[4-i] + multiplied_19[2]*g_elements[3-i] + 
               multiplied_19[1]*g_elements[2-i] + multiplied_19[0]*g_elements[i+1] : 0;
        multiplied_elements[i] += carry;
        result_elements[i] = ((uint64_t)multiplied_elements[i]) & mask;
        carry = (uint64_t)(multiplied_elements[i]>>51);
    }
     
    result_elements[0] += carry*19;
    carry = result_elements[0] >> 51;
    result_elements[0] &= mask;   
    result_elements[1] += carry;
    carry = result_elements[1] >> 51;
    result_elements[1] &= mask;
    result_elements[2] += carry;

    for(int i=0; i<5; i++) 
    {
        h[i]=result_elements[i];
    }
}