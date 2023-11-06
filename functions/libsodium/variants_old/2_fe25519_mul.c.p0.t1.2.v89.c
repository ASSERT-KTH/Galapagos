fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4, a, b, c, d, e;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  r00, r01, r02, r03, r04, carry;

    uint128_t f_factors[5] = {f[0], f[1], f[2], f[3], f[4]};
    uint128_t g_factors[5] = {g[0], g[1], g[2], g[3], g[4]};

    for (int i = 0; i < 5; i++){
      if(i==0){
        f0 = f_factors[i];  g0 = g_factors[i];
        r0 = a = f0 * g0;
      }else if(i==1){
        f1 = f_factors[i];  g1 = g_factors[i];
        f1_19 = 19ULL * f1;
        r1 = b = f0 * g1 +    f1 * g0;
        r0 += f1_19 * g4;
      }else if(i==2) {
        f2 = f_factors[i];  g2 = g_factors[i];
        f2_19 = 19ULL * f2;
        r2 = c = f0 * g2 +    f1 * g1 +    f2 * g0;
        r0 += f2_19 * g3;   r1 += f2_19 * g4;
      }else if(i==3) {
        f3 = f_factors[i];  g3 = g_factors[i];
        f3_19 = 19ULL * f3;
        r3 = d = f0 * g3 +    f1 * g2 +    f2 * g1 +    f3 * g0; 
        r0 += f3_19 * g2;   r1 += f3_19 * g3;   r2 += f3_19 * g4;
      }else{
        f4 = f_factors[i];  g4 = g_factors[i];
        f4_19 = 19ULL * f4;
        r4 = e = f0 * g4 +    f1 * g3 +    f2 * g2 +    f3 * g1 +    f4 * g0;
        r0 += f4_19 * g1;   r1 += f4_19 * g2;   r2 += f4_19 * g3;   r3 += f4_19 * g4;
      }
    }

    reduction(carry, r_custom, mask,r0,r1,r2,r3,r4);
    h[0] = r_custom[0];
    h[1] = r_custom[1];
    h[2] = r_custom[2];
    h[3] = r_custom[3];
    h[4] = r_custom[4];
} 

void reduction(uint64_t &carry, uint64_t r[], const uint64_t &mask, uint128_t r0, uint128_t r1, uint128_t r2, uint128_t r3, uint128_t r4){
     r[0]     = ((uint64_t) r0) & mask;
     carry  = (uint64_t) (r0 >> 51);
     r1    += carry;
     r[1]    = ((uint64_t) r1) & mask;
     carry  = (uint64_t) (r1 >> 51);
     r2    += carry;
     r[2]    = ((uint64_t) r2) & mask;
     carry  = (uint64_t) (r2 >> 51);
     r3    += carry;
     r[3]    = ((uint64_t) r3) & mask;
     carry  = (uint64_t) (r3 >> 51);
     r4    += carry;
     r[4]    = ((uint64_t) r4) & mask;
     carry  = (uint64_t) (r4 >> 51);
     r[0]   += 19ULL * carry;
     carry  = r[0] >> 51;
     r[0]   &= mask;
     r[1]   += carry;
     carry  = r[1] >> 51;
     r[1]   &= mask;
     r[2]   += carry;
 }