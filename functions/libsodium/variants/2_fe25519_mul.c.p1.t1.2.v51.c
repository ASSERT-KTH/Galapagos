Sure, here's a variant that has loops instead for some operations which maintains the original functionality:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
  const uint64_t mask = 0x7ffffffffffffULL;
  uint128_t r[5];
  uint128_t tmp_f[5];
  uint128_t f19[4];
  uint128_t g_bytes[5];
  uint64_t r_bytes[5];
  uint64_t  carry = 0;
  int i, j;

  for (i = 0; i < 5; i++)
    tmp_f[i] = (uint128_t) f[i];

  for (i = 0; i < 5; i++)
    g_bytes[i] = (uint128_t) g[i];

  for (i = 1; i < 5; i++)
    f19[i - 1] = 19ULL * tmp_f[i];

  for (i = 0; i < 5; i++) {
    r[i] = tmp_f[0] * g_bytes[i];
    for (j = 1; j < 5; j++) {
      r[i] += (j <= i ? tmp_f[j] : f19[j - 1]) * g_bytes[i - j];
    }
  }

  for (i = 0; i < 5; i++) {
    r_bytes[i] = ((uint64_t)r[i]) & mask;       
    carry = (uint64_t) (r[i] >> 51);            
    if (i < 4)  r[i + 1] += carry;             
    else        r_bytes[0] += 19ULL * carry;   
    carry = r_bytes[i] >> 51;                   
    r_bytes[i] &= mask;                        
    if (i < 4)  r_bytes[i + 1] += carry;       
    else        r_bytes[0] += carry;             
  }
   
  for (i = 0; i < 5; i++)
      h[i] = r_bytes[i];
}
 

Besides those changes, all related operations among different variables aren't inline anymore (only multiplication is kept) and replaced into certain loops, which doesn't just shorten some lines, but also might improve efficiency due to the caching technique on some processor architectures.