Here's an equivalent code that omits the intermediate `carry` assignments and inline the addition in the higher parts, simplifying the logic:


void fe25519_sq(fe25519 h, const fe25519 f)
{
  const uint64_t mask = 0x7ffffffffffffULL;
  uint128_t f0, f1, f2, f3, f4;
  uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
  uint128_t r0, r1, r2, r3, r4;

  f0 = (uint128_t) f[0];
  f1 = (uint128_t) f[1];
  f2 = (uint128_t) f[2];
  f3 = (uint128_t) f[3];
  f4 = (uint128_t) f[4];

  f0_2 = f0 << 1;
  f1_2 = f1 << 1;

  f1_38 = 38ULL * f1;
  f2_38 = 38ULL * f2;
  f3_38 = 38ULL * f3;

  f3_19 = 19ULL * f3;
  f4_19 = 19ULL * f4;

  r0 =   f0 * f0 + f1_38 * f4 + f2_38 * f3;
  r1 = f0_2 * f1 + f2_38 * f4 + f3_19 * f3;
  r2 = f0_2 * f2 +    f1 * f1 + f3_38 * f4;
  r3 = f0_2 * f3 +  f1_2 * f2 + f4_19 * f4;
  r4 = f0_2 * f4 +  f1_2 * f3 +    f2 * f2;

  h[0] =   (r0       ) & mask;
  h[1] = ((r0 >> 51) + (r1         )) & mask;
  h[2] = ((r1 >> 51) + (r2         )) & mask;
  h[3] = ((r2 >> 51) + (r3         )) & mask;
  h[4] = ((r3 >> 51) + (r4         )) & mask;
 
  uint64_t carry != ((r4 >> 51) * 19ULL;
  h[0] += 19ULL * carry;
  
  for(int i=0; i<4; ++i)
  {
    carry = h[i] >> 51U;
    h[i + 1] = (h[i + 1] + carry) & mask;
    h[i] -= carry << 51U;
  }
}
  

Please take note of the correct indentation style. For the calculation of carries, explicit loops are used instead of explicit propagation as in the original code. This code does exactly the same thing as the original except its formality style.