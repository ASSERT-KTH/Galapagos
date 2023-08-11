fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_values[5], g_values[5];
    uint128_t f_values_scaled[5];
    uint64_t  r_values[5];
    uint64_t  carry;

    for (int i = 0; i < 5; i++) {
        f_values[i] = (uint128_t) f[i];
        g_values[i] = (uint128_t) g[i];
        if (i != 0) {
          f_values_scaled[i] = 19ULL * f_values[i];
        }
    }

    r[0] = f_values[0] * g_values[0] + f_values_scaled[1] * g_values[4] + f_values_scaled[2] * g_values[3] + f_values_scaled[3] * g_values[2] + f_values_scaled[4] * g_values[1];
    r[1] = f_values[0] * g_values[1] + f_values[1] * g_values[0] + f_values_scaled[2] * g_values[4] + f_values_scaled[3] * g_values[3] + f_values_scaled[4] * g_values[2];
    r[2] = f_values[0] * g_values[2] + f_values[1] * g_values[1] + f_values[2] * g_values[0] + f_values_scaled[3] * g_values[4] + f_values_scaled[4] * g_values[3];
    r[3] = f_values[0] * g_values[3] + f_values[1] * g_values[2] + f_values[2] * g_values[1] + f_values[3] * g_values[0] + f_values_scaled[4] * g_values[4];
    r[4] = f_values[0] * g_values[4] + f_values[1] * g_values[3] + f_values[2] * g_values[2] + f_values[3] * g_values[1] + f_values[4] * g_values[0];

    for (int i = 0; i < 5; i++) {
       r_values[i]    = ((uint64_t) r[i]) & mask;
       carry  = (uint64_t) (r[i] >> 51);
       
       if(i + 1 < 5) {
           r[i + 1] += carry;
       }
       
       if (i == 4) {
           r_values[0] +=  19ULL * carry;
           carry  = r_values[0] >> 51;
           r_values[0] &= mask;
       }
    }
    carry = r_values[1] >> 51;
    r_values[1] &= mask;
    r_values[2] += carry;

   for (int i = 0; i < 5; i++) {
       h[i] = r_values[i];
   }
}