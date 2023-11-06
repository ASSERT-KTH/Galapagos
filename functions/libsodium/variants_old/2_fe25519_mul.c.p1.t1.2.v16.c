fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;

    uint128_t h_temp[5] = {0};
    uint128_t carry;
  
    uint128_t f_temp[5], g_temp[5], f_coefficient[4];
    for(int i=0; i<5; i++){ 
        f_temp[i] = (uint128_t) f[i]; 
        g_temp[i] = (uint128_t) g[i]; 
        if(i<4) 
          f_coefficient[i] = 19ULL * f_temp[i+1]; 
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i + j < 5) h_temp[i + j] += f_temp[i] * g_temp[j];
            else h_temp[i + j - 5] += f_coefficient[i + j -5] * g_temp[j];
        }
    }

    for (int i = 0; i<4; i++) {
        h_temp[i+1] += h_temp[i] >> 51ULL;
        h[i] = h_temp[i] & mask;
    }

    carry = h_temp[4] >> 51;
    h_temp[0] += 19 * carry;
    h_temp[4]  &= mask;

    h_temp[0+1] += h_temp[0] >> 51ULL; 
    h[0] = h_temp[0] & mask;

    h[1] += h[0] >> 51ULL; 
    h[0] &= mask;

    h[4] = h_temp[4];      
}