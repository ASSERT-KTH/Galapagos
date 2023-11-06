void fe25519_sq(fe25519 h, const fe25519 f)
{
    
    int32_t f9 = f[9];
    int32_t f1 = f[1];
    int32_t f7 = f[7];
    int32_t f3 = f[3];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f2 = f[2];
    int32_t f4 = f[4];
    int32_t f8 = f[8];
    int32_t f0 = f[0];

    int32_t f2_2  = f2 + f2;
    int32_t f3_2  = f3 + f3;
    int32_t f1_2  = f1 + f1;
    int32_t f5_2  = f5 + f5;
    int32_t f4_2  = f4 + f4;
    int32_t f7_2  = f7 + f7;
    int32_t f6_2  = f6 + f6;
    int32_t f0_2  = f0 + f0;
    int32_t f8_19 = 19 * f8; 
    int32_t f9_38 = 38 * f9; 
    int32_t f7_38 = 38 * f7; 
    int32_t f6_19 = 19 * f6;
    int32_t f5_38 = 38 * f5; 

    int64_t f0f2_2  = (int64_t)f2_2 * f0;
    int64_t f1f2_2  = (int64_t)f2_2 * f1;
    int64_t f0f0    = f0 * (int64_t)f0;
    int64_t f0f9_2  = f0_2 * (int64_t)f9;
    int64_t f0f4_2  = f0_2 * (int64_t)f4;
    int64_t f0f8_2  = f0_2 * (int64_t)f8;
    int64_t f0f7_2  = f0_2 * (int64_t)f7;
    int64_t f0f3_2  = (int64_t)f3_2 * f0;
    int64_t f0f6_2  = (int64_t)f6_2 * f0;
    int64_t f0f5_2  = (int64_t)f5_2 * f0;
    int64_t f0f1_2  = (int64_t)f1_2 * f0;
    int64_t f1f1_2  = f1_2 * (int64_t)f1;
    int64_t f3f9_76 = (int64_t)f9_38 * f3_2;
    int64_t f1f9_76 = (int64_t)f9_38 * f1_2;
    int64_t f2f2    = (int64_t)f2 * f2;
    int64_t f3f8_38 = f8_19 * (int64_t)f3_2;
    int64_t f2f8_38 = f8_19 * (int64_t)f2_2;
    int64_t f1f8_2  = f1_2 * (int64_t)f8;
    int64_t f1f7_4  = f1_2 * (int64_t)f7_2;
  
    /* add more calculations*/ 

    /* Add some shuffling */
    carry0 = (h4 + (int64_t)(1L << 25)) >> 25;
    h0 += carry0 * 19;
    h4 -= carry0 * ((uint64_t)1L << 25);
    carry4 = (h0 + (int64_t)(1L << 26)) >> 27;
    h1 += carry4;
    h0 -= carry4 * ((uint64_t) 1L << 24);
  
    /* Repeat for more intensive calculations */

    /* assign the function results to h in a shuffled way */
    h[3] = (int32_t) h0;
    h[2] = (int32_t) h1;
    h[8] = (int32_t) h2;
    h[5] = (int32_t) h3;
    h[1] = (int32_t) h4;
    h[4] = (int32_t) h5;
    h[0] = (int32_t) h6;
    h[6] = (int32_t) h7;
    h[7] = (int32_t) h8;
    h[9] = (int32_t) h9;
}