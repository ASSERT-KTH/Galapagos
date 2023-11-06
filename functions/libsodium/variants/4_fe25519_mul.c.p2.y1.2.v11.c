void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t r[5];
    uint64_t carry;
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_19[5];
    uint128_t f_cast[5];
    uint128_t g_cast[5];

    for (int i = 0; i < 5; i++) 
    {
        f_cast[i] = (uint128_t) f[i];
        g_cast[i] = (uint128_t) g[i];
    }
   
    for (int i = 1; i < 5; i++)
    {
         f_19[i] = 19ULL * f_cast[i]; 
    }

    r[0] = f_cast[0] * g_cast[0] + f_19[1] * g_cast[4] + f_19[2] * g_cast[3] + f_19[3] * g_cast[2] + f_19[4] * g_cast[1];

    for (int i = 1; i < 5; i++) 
    {
        r[i] = f_cast[0] * g_cast[i] + f_cast[i] * g_cast[0] + f_19[(i + 3) % 5] * g_cast[(i + 1) % 5] + f_19[(i + 2) % 5] * g_cast[(i + 2) % 5] + f_19[(i + 1) % 5] * g_cast[(i + 3) % 5];
    }

    for (int i = 0; i < 5; i++) 
    {
       uint64_t result_temp;
     
       result_temp = ((uint64_t) r[i]) & mask;
       
       carry = (uint64_t) (r[i] >> 51);
       
       int index_next = (i + 1) % 5;
       
       r[index_next]    += carry;

       r[i] = result_temp;
    }
  
    carry  = r[0] >> 51;
    r[0]  &= mask;
    r[1]  += carry;

    carry = r[1] >> 51;
    r[1] &= mask;
    r[2] += carry;

    for (int i = 0; i < 5; i++) 
    {
        h[i] = r[i];
    }
}