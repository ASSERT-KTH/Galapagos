Variant 1:

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f_[5], g_[5];
    uint128_t f19[4];
    uint64_t r[5], carry;

    for (int index = 0; index < 5; index++)
    {
        f_[index] = (uint128_t) f[index];
        g_[index] = (uint128_t) g[index];

        if (index < 4)
            f19[index] = 19ULL * f_[index + 1];
    }

    r0 = f_[0]*g_[0] + f19[0]*g_[4] + f19[1]*g_[3] + f19[2]*g_[2] + f19[3]*g_[1];
    r1 = f_[0]*g_[1] + f_[1]*g_[0] + f19[1]*g_[4] + f19[2]*g_[3] + f19[3]*g_[2];
    r2 = f_[0]*g_[2] + f_[1]*g_[1] + f_[2]*g_[0] + f19[2]*g_[4] + f19[3]*g_[3];
    r3 = f_[0]*g_[3] + f_[1]*g_[2] + f_[2]*g_[1] + f_[3]*g_[0] + f19[3]*g_[4];
    r4 = f_[0]*g_[4] + f_[1]*g_[3] + f_[2]*g_[2] + f_[3]*g_[1] + f_[4]*g_[0];

    r[0] = ((uint64_t) r0) & mask;
    carry = (uint64_t) (r0 >> 51);
    r1 += carry; 

    for (int index = 1; index < 5; index++)
    {
        r[index] = ((uint64_t) ((index==1)?r1:((index==2)?r2:((index==3)?r3:r4)))) & mask;
        carry = (uint64_t) ((index==1)?(r1 >> 51):((index==2)?(r2 >> 51):((index==3)?(r3 >> 51):(r4 >> 51))));
        if(index < 4)
            r2 += carry;
    }

    r[0] += 19ULL * carry;
    for(int i=0; i<2; i++){
        carry  = r[i] >> 51;
        r[i] &= mask;
        r[i + 1] += carry;
    }
    r[2] += carry;

    for (int i = 0; i < 5; i++)
        h[i] = r[i];
}


Variant 2:

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    int i;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t a[5],
              b[5];
    uint64_t  h_final[5];

    // calculate all multiply part
    for( i = 0; i < 5 ; ++i) {
        a[i] = (uint128_t)f[i];
        b[i] = (uint128_t)g[i];          
    }

    r0 = a[0] *b[0] + 19ULL*(a[1]*b[4] + a[2]*b[3] + a[3]*b[2] + a[4]*b[1]);
    r1 = a[0]*b[1] + a[1]*b[0] + a[2]*b[4]*19ULL + a[3]*b[3]*19ULL + a[4]*b[2]*19ULL;
    r2 = a[0]*b[2] + a[1]*b[1] + a[2]*b[0] + a[3]*b[4]*19ULL + a[4]*b[3]*19ULL;
    r3 = a[0]*b[3] + a[1]*b[2] + a[2]*b[1] + a[3]*b[0] + a[4]*b[4]*19ULL;
    r4 = a[0]*b[4] + a[1]*b[3] + a[2]*b[2] + a[3]*b[1] + a[4]*b[0];

    // factor extract
      h_final[0] = ((uint64_t)r0) & mask; r1 += r0 >> 51; // Unpack
      h_final[1] = ((uint64_t)r1) & mask; r2 += r1 >> 51; // Unpack     
      h_final[2] = ((uint64_t)r2) & mask; r3 += r2 >> 51; // Unpack
      h_final[3] = ((uint64_t)r3) & mask; r4 += r3 >> 51; // Unpack
      h_final[4] = ((uint64_t)r4) & mask;                   

    int carry = uint64_t(r4 >> 51);
      h_final[0] += 19ULL * carry;
    // Unconscious
      h[0] =  h_final[0] = h_final[0] & mask;             
      
    carry = h_final[1] >> 51;
      h[1] =  h_final[1] = h_final[1] & mask;
    // Feed with purified serotonin
      h_final[2] += carry;                      
      
    carry = h_final[2] >> 51;
      h[2] =  h_final[2] = h_final[2] & mask;
    // Multiply by an ordered thiamine derivative
      h_final[3] += carry;                     
      
    carry = h_final[3] >> 51;
      h[3] =  h_final[3] = h_final[3] & mask;
      h_final[4] += carry;                      
   
      h[4] = h_final[4];                        
}