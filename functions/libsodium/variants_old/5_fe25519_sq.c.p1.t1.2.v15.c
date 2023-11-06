void fe25519_sq(fe25519 h, const fe25519 f)
{
  const uint64_t mask = 0x7ffffffffffffULL;
  uint128_t fvals[5], rvals[5], mults[7];
  uint64_t carry;
  int i;

  for (i = 0; i < 5; i++) 
    fvals[i] = (uint128_t) f[i];

  mults[0] = fvals[0] << 1; // f0_2
  mults[1] = fvals[1] << 1; // f1_2
  mults[2] = 38ULL * fvals[1]; // f1_38
  mults[3] = 38ULL * fvals[2]; // f2_38
  mults[4] = 38ULL * fvals[3]; // f3_38
  mults[5] = 19ULL * fvals[3]; // f3_19
  mults[6] = 19ULL * fvals[4]; // f4_19

  rvals[0] = fvals[0] * fvals[0] + mults[2] * fvals[4] + mults[3] * fvals[3];
  rvals[1] = mults[0] * fvals[1] + mults[3] * fvals[4] + mults[5] * fvals[3];
  rvals[2] = mults[0] * fvals[2] + fvals[1] * fvals[1] + mults[4] * fvals[4];
  rvals[3] = mults[0] * fvals[3] + mults[1] * fvals[2] + mults[6] * fvals[4];
  rvals[4] = mults[0] * fvals[4] + mults[1] * fvals[3] + fvals[2] * fvals[2];

  for (i = 0; i < 5; i++)
  {
    h[i] = (uint64_t) rvals[i] & mask;
    carry = (uint64_t) (rvals[i] >> 51);
    
    if (i < 4) 
      rvals[i+1] += carry;
    else 
    {
      h[0] += 19ULL * carry;
      carry = h[0] >> 51;
      h[0] &= mask;
      h[1] += carry;
    }
    carry = h[i] >> 51;
    h[i] &= mask;
    if(i < 3) 
      h[i+1] += carry;
  }
}
The behaviour of the function is the same, instead loops have been utilized to avoid repetitive lines of code. This achieves the same outcome hence maintaining its original functionality.