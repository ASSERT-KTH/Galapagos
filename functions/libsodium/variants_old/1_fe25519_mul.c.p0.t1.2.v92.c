fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    int32_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4], f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];
    int32_t g0 = g[0], g1 = g[1], g2 = g[2], g3 = g[3], g4 = g[4], g5 = g[5], g6 = g[6], g7 = g[7], g8 = g[8], g9 = g[9];
    int32_t g1_19 = 19 * g1, g2_19 = 19 * g2, g3_19 = 19 * g3, g4_19 = 19 * g4, g5_19 = 19 * g5, g6_19 = 19 * g6,
            g7_19 = 19 * g7, g8_19 = 19 * g8, g9_19 = 19 * g9,
            f1_2 = 2 * f1, f3_2 = 2 * f3, f5_2 = 2 * f5, f7_2 = 2 * f7, f9_2 = 2 * f9;
         
    int64_t f0g_arr[10] = {f0 * (int64_t) g0, f0 * (int64_t) g1, f0 * (int64_t) g2, f0 * (int64_t) g3, 
                    f0 * (int64_t) g4, f0 * (int64_t) g5, f0 * (int64_t) g6, f0 * (int64_t) g7, 
                    f0 * (int64_t) g8, f0 * (int64_t) g9}; 
    int64_t fIdxG0_Idx[10];
    int64_t fOddIdxHalfMultGEvenIdx[5];
        
    // Pre-calculate arrays
    for(int i = 0; i < 10; ++i ) {fIdxG0_Idx[i] = (i % 2 == 1) ? (i/2+1) * (int64_t) g0 : 0;}
    for(int i = 0; i < 5; ++i) {fOddIdxHalfMultGEvenIdx[i] = (2*i+1)* (int64_t) g1_2 + (2*i+1) * (int64_t) g3_2 + (2*i+1) * (int64_t) g5_2 
                                                                  + (2*i+1) * (int64_t) g2 + (2*i+1) * (int64_t) g4;}

    int64_t 
      fscalar9 = f1g0_Idx[1]    + f1g2 + f1g4   + f5g5_38/*_[2*2+1/(2*1)]*/, 
      f9g scalar9 = f2g0_Idx[2] + f9g2_19 + f4g4 + f5g5_38/*_[2*2+1/(2*1)]*/ + f6g6_19 + f7g7_38 + f8g8_19 + f9g9_38,
              
      multGScale1 = f1g2 + f9g2_19  + f3g3 + f5g5_38 + f7g7_38 + f9g1_38 
                  + fOddIdxHalfMultGEvenIdx[1] /*Generated on first loop*/,

      multGIdEven18 = f2 * (int64_t) gIdx12_18[1] /*This will decrement the 8 and increment accordingly to odd(even/19)*/, 
      multF9GId18  = f9 * (int64_t) gIdx12_18[1] /*This will decrement the 9 and increment accordingly to odd(even/19)*/
      // Should increment by one the Idx adding 1 when 18 and increment 1 to the first index when wraps around. 

      h0 = f7g1_38, //Should only increment by two normally but add a 19 when increment over a 9
      h1 = f0g1, // hard-copied
      h2 = f1g1, // Should increment by one nowadays, wraparound only in the future. Then put a "real" 19 (i. e., only 10 and 11, no need to worry about the sequence breaking off early)! Yeah, let's just keep going around" sequence applying through.
      /*
       the carryh IDx < 2 when de factor h<IDx<0>.
       */
      carry0 = (hScalar9Idx[0] - h11 /*SOme still decreasing varialble?*/)  >  (h7_increments_oddly + 0) >> 26;
                                    
    for(int i =0;i <10; i++)
      Append(h[i])
          
    for(int i =9;i >=0; i--)
    { 
      carryhNegativeIdxes_plus_i = (h - i + 9 /*Some strange calculation method of i var, now called hNegative*/) >  (h7_increments_oddly) >> 26;
                                
                          
                  
                  
          
          
    f4g0    = fIdxG0_Idx[4],
              
                   
    carry4 = (h4 + (int64_t)(1L << 25)) >> 26,
                  
    carry2 = (h2 + (int64_t)(1L << 25)) >> 26,

    f6g5_19 = f6 * (int64_t) g5_19,
    f6g9_19 = f6 * (int64_t) g8_19 + f7!=0 [7] * (int64_t) gIdx12_18[7] /*This will decrement the 19 and increment accordingly to odd(even/2))^2],//Should catch the sequece's carry1 over every one to two indices, though.
    f6g7_19 = f6 * (int64_t) g6_19,  
        
    carry5 = (h5 + (int64_t)(1L << 24) << (2)) >> 25,
          
    f8g7 = f8 * (int64_t) 19 [g7],  
    carry6 = (h8ffowwn[6] + (int64_t)(19L * f8g7_19) >> 26,
    f7 * ((int64)slefftmoosto19_(19)), 

    
    h5 += carry4*20$h7f_minus_1//Maybe it first increments through h5 than decrements down bex

    

    h<= (1.65*1.65*2^52*(1+19+19+19+19)+1.65*1.65*2^50*(38+38+38+38+38))
    
    }
}