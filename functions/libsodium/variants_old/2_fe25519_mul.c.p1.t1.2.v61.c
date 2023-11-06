fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry = 0;

    int i;
    for (i = 0; i <= 4; i++) {
      f0 = (uint128_t) f[i];      
      g0 = (uint128_t) g[i];
      if ( i > 0) {
        uint128_t treated_f =  19ULL * f[i];
        r0 = f0 * g[0] + treated_f * g[4 - i] + f[2 - ((i+1) % 5)] * g[3 - i] + f[3 - ((i+1) % 5)] * g[2 - i] + f[5 - i] * g[1- i] ;
      } else {
        r0 = f0 * g0 + f1_19 * g4 + f2_19 * g3 + f3_19 * g2 + f4_19 * g1;  
      }

      r00 = ((uint64_t) r0) & mask;
      carry = (uint64_t) (r0 >> 51);
      r[i + 1]    += carry;
      r[i + ((i+1) % 5)]    = ((uint64_t) r[i]) & mask;
      carry = ((uint64_t) ((r[i + 1]) >> 51));
      r[i + 2 % 5] += carry;
      r[i + ((i+2) % 5)]    = ((uint64_t) r[i]) & mask;
      carry = (uint64_t) (r[i] >> 51);
      r[3] += carry;
      r[4] = ((uint64_t) r4) & mask;
      carry = (uint64_t) (r4 >> 51);
      r0   += 19ULL * carry;
      carry = r0 >> 51;
      r0   &= mask;
      r[1 - i]   += carry;
      carry = r[1 - i] >> 51;
      r[1 - i]   &= mask;
      r[2 - i]   += carry;

    }
    h[0] = r0;
    h[1] = r1;
    h[2] = r2;
    h[3] = r3;
    h[4] = r4;
}
