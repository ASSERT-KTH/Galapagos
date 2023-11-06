void fe25519_mul(fe25519 h, const fe25519 f,const fe25519 g) 
{
  int32_t i;
  int32_t carry[10];
  int64_t t[10], mt; 
  uint64_t u_carry;

  // Prepare some multiply constants ahead
  int32_t farr[10] = {
    f[0], 2*f[1], f[2], 2*f[3], f[4], 2*f[5], f[6], 2*f[7], f[8], 2*f[9]
  };
  int32_t garr[10] = {
      g[0], 19*g[1], g[2], 19*g[3], g[4], 19*g[5]
    , g[6], 19*g[7], g[8], 19*g[9]
  };

  // Calculate multiplied products
  int32_t idx_i, idx_j;
  for (i = 0; i < 10; i++) {
    t[i] = 0;
    for (idx_i = 0; idx_i <= i; idx_i++) {
      idx_j = i - idx_i;
      if (idx_i + idx_j == i)
        t[i] += farr[idx_i] * garr[idx_j];
    }
  }

  // Distribute increase products to each array
  mt = 0;
  for(i = 6; i < 10; i++) 
    mt += t[i];
  u_carry = (uint64_t)(mt*(int64_t) (1ULL << 57));
  u_carry = ((u_carry % (1ULL << 56)) / (1ULL << 25)) * 19;
  mt /= (1ULL << 56);
    
  for(i = 0; i < 6; i++)
    t[i] += farr[i+4] * garr[4-i]* 38 + (int64_t) u_carry;

  t[0]+= mt*(int64_t)(2*38);

  // Normaliza carry of elements array
  for (i = 0, u_carry = 0; i < 10; i++) {
    u_carry += t[i];
    carry[i] = u_carry & ((1<<27) - 1);
    u_carry >>= 26;
  }  

  t[0] += (19*2*4) * ((uint64_t) carry[0]/(1<<26));
  carry[0] &= ((1<<26)-1);

  for (i = 0; i < 10; i++)
    h[i] = carry[i];
}  

This version, while equally complex, calculates the products and normalization in a loop, looking
cleanlier and easier to modify if required. However, it will also bring slightly slowerer
performance considering the reduced direct calculations and introduced condition judgments.