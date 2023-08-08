fe25519_sq(fe25519 h, const fe25519 f)
{
    long int f0 = f[0];
    long int f1 = f[1];
    long int f2 = f[2];
    long int f3 = f[3];
    long int f4 = f[4];
    long int f5 = f[5];
    long int f6 = f[6];
    long int f7 = f[7];
    long int f8 = f[8];
    long int f9 = f[9];

    long int f0_2  = f0 << 1;
    long int f5_38 = f5 * 38;
    long int f6_19 = f6 * 19;
    long int f7_38 = f7 * 38;
    long int f8_19 = f8 * 19;
    long int f9_38 = f9 * 38;

    uint64_t f0f0    = f0 * (uint64_t) f0;
    uint64_t f0f5_2  = f0_2 * (uint64_t) f5;
    uint64_t f0f6_2  = f0_2 * (uint64_t) f6;
    uint64_t f0f7_2  = f0_2 * (uint64_t) f7;
    uint64_t f0f8_2  = f0_2 * (uint64_t) f8;
    uint64_t f0f9_2  = f0_2 * (uint64_t) f9;
    uint64_t f5f5_38 = f5 * (uint64_t) f5_38; 
    uint64_t f5f6_38 = f5_2 * (uint64_t) f6_19;
    uint64_t f5f7_38 = f5_2 * (uint64_t) f7_38;
    uint64_t f5f8_38 = f5_2 * (uint64_t) f8_19;
    uint64_t f5f9_38 = f5_2 * (uint64_t) f9_38;

    uint64_t h0 = f0f0  + 2*f0f5_2  + f5f5_38;
    uint64_t h1 = f0f5_2  + f0f6_2  +2* f5f6_38;
    uint64_t h2 = f0f6_2  + f0f7_2  +2* f5f7_38;
    uint64_t h3 =  f0f7_2  +  f0f8_2 + 2*f5f8_38;
    uint64_t h4 =  f0f8_2 +  f0f9_2  + 2*f5f9_38;
  
    uint64_t carry0;
    uint64_t carry1;
    uint64_t carry2;
    uint64_t carry3;
    uint64_t carry4;

    carry0 = (h0 + ((uint64_t)1L << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 << 26; 
        
    carry1 = (h1 + ((uint64_t)1L << 25)) >> 26;
    h2 += carry1;
    h1 -= carry1 << 26;
  
    carry2 = (h2 + ((uint64_t)1L << 25)) >> 26;
    h3 += carry2;
    h2 -= carry2 << 26; 

    carry3 = (h3 + ((uint64_t)1L << 25)) >> 26;
    h4 += carry3;
    h3 -= carry3 << 26; 

    carry4 = (h4+ ((uint64_t)1L << 25)) >> 26;
    h0 += carry4 *19;
    h4 -= carry4 << 26; 
    
    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    h[2] = (int32_t) h2;
    h[3] = (int32_t) h3;
    h[4] = (int32_t) h4;
}
